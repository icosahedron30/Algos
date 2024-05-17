#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int f(int n, int k){
    cout << n << ' ' << k << ":\n";
    int x; cin >> x;
    return x;
}


vector <int> solve(int n, int m);
void rec(vector <int> &rows, vector <int> &columns, vector <int> &ans);
vector <int> reduce(vector <int>& rows, vector <int>& columns);
void interpolate(vector <int>& rows, vector <int>& columns, vector <int>&ans);

int main() {
    int n, m; cin >> n >> m;
    vector <int> res = solve(n, m);
    for(int to : res){
        cout << to << ' ';
    }
    cout << '\n';
}

vector <int> solve(int n, int m){
    vector <int> rows, columns, ans;
    for(int i = 0; i < n; i++)
        rows.push_back(i);
    for(int i = 0; i < m; i++)
        columns.push_back(i);
    ans.resize(n);
    rec(rows, columns, ans);
    return ans;
}

void rec(vector <int> &rows, vector <int> &columns, vector <int> &ans){
    if(rows.size() == 1 && columns.size() == 1){
        ans[rows[0]] = columns[0];
        return;
    }
    if(columns.size() > rows.size()){
        vector <int> new_columns = reduce(rows, columns);
        rec(rows, new_columns, ans);
    } else {
        interpolate(rows, columns, ans);
    }
}

vector <int> reduce(vector <int> &rows, vector <int> &columns){
    int n = rows.size();
    stack <int> st;
    vector <int> leaders(columns.size(), 0);
    for(int i = 0; i < columns.size(); i++){
        int j = columns[i];
        while(!st.empty()){
            int id = st.top();
            int l= columns[id];
            if(f(leaders[id], l) >= f(leaders[id], j)){
                st.pop();
                leaders[i] = leaders[id];
                leaders[id] = n;
            }
            else{
                leaders[i] = leaders[id] + 1;
                break;
            }
        }
        if(leaders[i] < n)
            st.push(i);
    }
    vector <int> new_columns;
    for(int i = 0; i < columns.size();i++){
        if(leaders[i] < n)
            new_columns.push_back(columns[i]);
    }
    return new_columns;
}


void interpolate(vector <int> &rows, vector <int> &columns, vector <int>&ans){
    vector <int> odd_rows;
    for(int i = 0; i < rows.size(); i += 2){
        odd_rows.push_back(rows[i]);
    }
    rec(odd_rows, columns, ans);
    int ind = 0;
    while(ind < (int)columns.size() - 1 && columns[ind + 1] <= ans[rows[0]]){
        ind++;
    }

    for(int i = 1; i < rows.size(); i += 2){
        int mn = 1e9 + 1;
        int R = columns.back();
        if(i < (int)rows.size() - 1){
            R = ans[rows[i + 1]];
        }
        mn = f(rows[i], columns[ind]), ans[rows[i]] = columns[ind];
        while(ind < (int)columns.size() - 1 && columns[ind + 1] <= R) {
            ind++;
            int x = f(rows[i], columns[ind]);
            if (x < mn)
                mn = x, ans[rows[i]] = columns[ind];
        }

    }
}
