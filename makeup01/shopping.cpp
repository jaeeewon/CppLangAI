// 온라인 쇼핑몰 -> 쇼핑

// 1. 로그인 - 계정 정보 구조체: Customer
// 2. 상품을 장바구니, 결제
// 3. 하나씩 배송

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

struct Customer
{
    string name;
    string password;
};

struct Order
{
    int customerId;
    string product;
    int quantity;
};

int main()
{
    unordered_map<int, Customer> customers{
        {1001, {"kim", "pw1001"}},
        {1002, {"lee", "pw1002"}},
        {1003, {"park", "pw1003"}},
    };
    // string -> 비교가 느림, double -> 비교가 안전하지 않음(정밀도 문제: 다른데 같다, 같은데 다르다)
    // int -> 한 번에 정확히 비교 가능

    // 상품 정보(재고 정보)
    map<string, int> stock{
        {"Electronics:Phone", 10},
        {"Electronics:Laptop", 5},
        {"Books:CPP_Primer", 20},
        {"Food:Coffee", 50},
    };

    vector<Order> orders;

    // 쇼핑몰 과정 코드 구현

    while (true)
    {
        cout << "=== LOGIN (enter 0 to exit) ===\n"
             << "id: ";
        string id;
        cin >> id;

        if (id == "0")
            break;

        cout << "password: ";
        string pw;
        cin >> pw;

        int currid = -1;
        bool cfind = false;
        for (const auto &[cid, cinfo] : customers)
        {
            string cname = cinfo.name;
            string cpw = cinfo.password;

            if (id == cname && pw == cpw)
            {
                cfind = true;
                currid = cid;
                break;
            }
        }

        if (!cfind)
        {
            cout << "invalid customer information!\n";
            continue;
        }

        cout << "Welcome, " << id << "!\n";

        while (true)
        {
            cout << "Type a product name to order (or \"logout\")\n";
            cout << "Available stock:\n";
            for (const auto &[item, qty] : stock)
            {
                cout << " " << item << ": " << qty << '\n';
            }

            string product;
            cin >> product;

            if (product == "logout")
            {
                cout << "logged out!\n";
                break;
            }

            cout << "Quantity: ";
            int qty;
            cin >> qty;

            if (!stock.count(product))
            {
                cout << "Unknown produt.\n";
                continue;
            }
            if (stock[product] < qty)
            {
                cout << "Insufficient stock.\n";
                continue;
            }

            Order ord{currid, product, qty};
            orders.push_back(ord);
            stock[product] -= qty;

            cout << "Order accepted!\n";
        }
    }

    cout << "=== Shopping Information ===\n";
    for (const auto &[cid, prod, qty] : orders)
    {
        cout << qty << " " << prod << "s to " << customers[cid].name + '\n';
    }

    return 0;
}