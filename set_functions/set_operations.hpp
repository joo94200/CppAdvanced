#include <set>

std::set<int> operator+(const std::set<int> &lhs, const std::set<int> &rhs)
{
    std::set<int> s(lhs);
    s.insert(rhs.begin(), rhs.end());
    return s;
}

std::set<int> operator-(const std::set<int> &lhs, const std::set<int> &rhs)
{
    std::set<int> s;
    for (int keyL : lhs){
        bool check = true;
        for (int keyR : rhs){
            if (keyL == keyR){
                check = false;
            }
        }
        if (check){
            s.insert(keyL);
        }
    }
    return s;
}


std::set<int> operator^(const std::set<int> &lhs, const std::set<int> &rhs)
{
    std::set<int> s;
    for (int keyL : lhs){
        bool check = true;
        for (int keyR : rhs){
            if (keyL == keyR){
                check = false;
            }
        }
        if (check){
            s.insert(keyL);
        }
    }
    for (int keyR : rhs){
        bool check = true;
        for (int keyL : lhs){
            if (keyL == keyR){
                check = false;
            }
        }
        if (check){
            s.insert(keyR);
        }
    }
    return s;
}

std::set<int> operator*(const std::set<int> &lhs, const std::set<int> &rhs)
{
    std::set<int> s;
    for (int keyL : lhs){
        for (int keyR : rhs){
            s.insert(keyL + keyR);
        }
    }
    return s;
}

std::set<int> operator^(const std::set<int> &lhs, const int n)
{
    std::set<int> s;
    for (int keyL : lhs){
        for (int i = 1; i < n; i++){
            s = lhs*lhs;
        }
    }
    return s;
}

std::set<std::string> operator^(const std::set<std::string> &lhs, const int n)
{
    return lhs;
}
