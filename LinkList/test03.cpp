//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//struct node {
//    int next, tre;
//    node(int nn, int tt) :next(nn), tre(tt) {}//参数构造函数
//    node() {}//默认构造函数
//};
//vector<node> road[1005];
//int start[1005];
//int dp[1005];
//int dfs(int n) {
//    if (dp[n] > 0)return dp[n];
//    int ans = 0;
//
//    for (int i = 0; i < road[n].size(); i++) {
//        ans = max(ans, dfs(road[n][i].next) + road[n][i].tre);
//    }
//    dp[n] = ans;
//    return dp[n];
//}
//int main()
//{
//    int T, n, m;
//    cin >> T;
//    int a, b, c;
//    while (T--) {
//        cin >> n >> m;
//        memset(start, 0, sizeof(start));
//        memset(dp, 0, sizeof(dp));
//        for (int i = 0; i < m; i++) {
//            cin >> a >> b >> c;
//            road[a].push_back(node(b, c));
//            start[b] = 1;
//        }
//        for (int i = 0; i < n; i++) {
//            if (start[i] == 0) {
//                dfs(i);
//            }
//        }
//        cout << *max_element(dp, dp + n) << endl;//返回dp数组中最大值
//        for (int i = 0; i < n; i++)road[i].clear();//将路径清零
//    }
//}