#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <random>
#include <fstream>

using namespace std;

// 선형대수적 함수들

// 벡터의 내적
double dot(const vector<double> &a, const vector<double> &b)
{
    // a = [1.0, 0.5, -0.5, -1.0]
    // b = [0.0, -0.5, 0.5, -1.0]
    // out = 0.0 + (-0.25) + (-0.25) + 1.0
    double out = 0.0;
    for (size_t i = 0; i < a.size(); ++i)
    {
        out += a[i] * b[i];
    }
    return out;
}

double sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

void cadd(vector<double> &a, const vector<double> &b, double alpha)
{
    // 두 개의 벡터 합(더해지는 애에게 b alpha 곱해서 더해줌)
    for (size_t i = 0; i < a.size(); ++i)
    {
        a[i] += alpha * b[i];
    }
}

double similarity(vector<double> &a, vector<double> &b)
{
    double d = dot(a, b);
    double na = sqrt(dot(a, a)); // norm
    double nb = sqrt(dot(b, b));
    return d / (na * nb + 1e-9); // cosine similarity -> 베터 방향의 유사도
    // thetha == 0 -> 1, thetha == pi / 2 -> 0
}

int main()
{
    // string word;
    // string sentence = "";
    // while (cin >> word)
    // {
    //     sentence += word + " ";
    //     cout << word << '\n';
    //     // "\n" << 줄 바꿈만
    //     // "\n" << 줄도 바꾸고 buffer 청소
    // }

    // Word embedding: '단어 -> 벡터(수학)' 매핑
    // Word2Vec (2009, Google)

    // corpus: 텍스트 데이터
    // 단어 단위로 데이터를 쪼갬(Word2vec) -> 토큰화, 토큰
    // const vector<string> corpus = {"i", "like", "c", "programming"};

    ifstream fin("text8.txt");
    string word;
    vector<string> corpus;
    while (fin >> word)
    {
        corpus.push_back(word);
    }

    // 단어마다 벡터를 하나씩 줌
    unordered_map<string, int> id;
    vector<string> vocab;

    for (const auto &w : corpus)
    {
        if (!id.count(w))
        {
            // count -> 개수
            // w가 id 안에 없을 때
            id[w] = vocab.size();
            vocab.push_back(w);
        }
    }

    // 텍스트 전처리

    const int V = vocab.size();
    const int D = 20; // Vector의 차원

    const int WINDOW = 3;
    const int NEG = 15;
    const int ITER = 100000;
    const double LR = 0.05;

    // 단어 하나마다 벡터를 하나씩 줌
    vector<vector<double>> W_in(V, vector<double>(D));
    vector<vector<double>> W_out(V, vector<double>(D));

    // 단어와 벡터 사이의 매핑
    // 'i'              ---id['i']-------------> 0  --> W_in[0], W_out[0]
    // "like"           ---id["like"]----------> 1  --> W_in[1], W_out[1]
    // 'c'              ---id['c']-------------> 2  --> W_in[2], W_out[2]
    // "programming"    ---id["programming"]---> 3  --> W_in[3], W_out[3]

    // AI 학습 -> 대응된 벡터들이 실제로 의미를 갖도록

    // 딥러닝 초기화: 적당한 범위의 랜덤 실수 벡터, 행렬 할당
    mt19937 gen(42); // 변수라면 변수인 Object하나 생성
    uniform_real_distribution<double> urand(-0.5 / D, 0.5 / D);
    for (auto &v : W_in)
    {
        for (double &x : v)
        {
            x = urand(gen); // +-0.025 안에서 랜덤한 거 뽑는
        }
    }

    uniform_int_distribution<int> uni_vocab(0, V - 1); // 0 ~ V-1 안에서 랜덤한 정수 뽑는

    // 진짜 학습

    for (int it = 0; it < ITER; ++it)
    {
        // 학습 반복
        int idx = it % corpus.size(); // idx -> 0 ~ corpus.size() - 1 -> 코퍼스 특정 단어 가지고 옴
        int center = id[corpus[idx]]; // 가지고 온 단어의 id 값

        // Word2vec
        // center 단어 주변에서 나타나는 단어(positive sample 가지고 옴
        // center 단어의 벡터, 주변 단어의 벡터 내적 -> 값 -> 점수 증가
        // center 단어 주변에서 안 나타나는 단어(negative sample 가지고 옴
        // center 단어의 벡터, 주변 단어의 벡터 내적 -> 값 -> 점수 감소

        vector<int> positive;
        for (int offset = -WINDOW; offset <= WINDOW; ++offset)
        {
            int pos = idx + offset;
            if (pos >= 0 && pos < corpus.size() && offset != 0)
                positive.push_back(id[corpus[pos]]);
            // 현재 center단어의 위치는 idx에 있음
            // offset 변수 증가시켜 나감(WINDOW 범위) 주변 단어를 하나씩 추가
            // w1, w2,    w3,    center, w4, w5, w6, w7, ...
            //          idx - 1   idx
        }

        double pos_score = 0;
        double neg_score = 0;

        for (auto i : positive)
        {
            double score = sigmoid(dot(W_in[center], W_out[i]));
            pos_score += score;
            // 점수 계산(0 ~ 1);
            double grad = 1.0 - score;
            cadd(W_in[center], W_out[i], grad * LR); // Learning Rate
            cadd(W_out[i], W_in[center], grad * LR);
            // score가 올라감!
            // Gradient Descent
            /**
             * Score의 함수가 있다고 해보자
             * 점수 올리려면 경사 올라가는 방향으로
             * 주변에 나올법한 것들에 높은 점수 주도록
             */
        }

        // Negative 업데이트
        // 주변에 안 나오는 단어 V-P개 -> 너무 많음
        // 몇 개만 랜덤하게 샘플링해서 업데이트

        for (int n = 0; n < NEG; ++n)
        {
            // positive에서 i를 neg
            int neg = uni_vocab(gen);

            double score = sigmoid(dot(W_in[center], W_out[neg]));
            neg_score += score;

            double grad = -score;
            cadd(W_in[center], W_out[neg], grad * LR);
            cadd(W_out[neg], W_in[center], grad * LR);
        }

        if (it % 10000 == 0)
            cout << "[Iter:" << it / 10000 << "0K] avg pos: " << pos_score / (2 * WINDOW) << " / avg neg: " << neg_score / NEG << "\n";
    }

    // 단어들 간 유사도 측정
    cout << "Cosine similarity between \"i\" and \"like\": " << similarity(W_in[id["i"]], W_in[id["like"]]);

    return 0;
}
/** word analogy
 *
 * woman - man = queen - king
 * king - man + woman = queen
 * seoul - korea + japan -> tokyo와 비슷한
 * went - go + eat -> ate
 */