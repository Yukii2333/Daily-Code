
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int N, m;
//    cin >> N >> m;
//    vector<pair<int, int>> items(m);  // 物品的金额和重要度
//    for (int i = 0; i < m; i++) 
//    {
//        cin >> items[i].first >> items[i].second;
//    }
//    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0)); // 创建用于存储最大总价值的动态规划表格
//    for (int i = 1; i <= m; i++) 
//    {
//        for (int j = 1; j <= N; j++) 
//        {
//            if (j >= items[i - 1].first) // 当前容量大于或等于当前物品重量时
//            { 
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].first] + items[i - 1].first * items[i - 1].second); // 在选择和不选择当前物品中取较大值
//            }
//            else {
//                dp[i][j] = dp[i - 1][j]; // 当前容量不足以选择当前物品，不选择该物品
//            }
//        }
//    }
//    cout << dp[m][N] << endl; // 输出最大总价值
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    vector<int> sizes; // 产品尺寸
//    sizes.resize(6);
//    for (int i = 0; i < sizes.size(); ++i) cin >> sizes[i];
//    int totalBoxes = 0; // 总箱数
//    for (int i = 0; i < 6; i++) {
//        int currentSize = sizes[i];
//        int boxesNeeded = currentSize * currentSize / 36; // 计算需要的箱数
//        if (currentSize * currentSize % 36 != 0) {
//            boxesNeeded++; // 如果有剩余空间，需要额外的箱子
//        }
//        totalBoxes += boxesNeeded; // 累计总箱数
//    }
//    std::cout << "最少需要 " << totalBoxes << " 个箱子" << std::endl;
//    return 0;
//}