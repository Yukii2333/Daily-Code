
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int N, m;
//    cin >> N >> m;
//    vector<pair<int, int>> items(m);  // ��Ʒ�Ľ�����Ҫ��
//    for (int i = 0; i < m; i++) 
//    {
//        cin >> items[i].first >> items[i].second;
//    }
//    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0)); // �������ڴ洢����ܼ�ֵ�Ķ�̬�滮���
//    for (int i = 1; i <= m; i++) 
//    {
//        for (int j = 1; j <= N; j++) 
//        {
//            if (j >= items[i - 1].first) // ��ǰ�������ڻ���ڵ�ǰ��Ʒ����ʱ
//            { 
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].first] + items[i - 1].first * items[i - 1].second); // ��ѡ��Ͳ�ѡ��ǰ��Ʒ��ȡ�ϴ�ֵ
//            }
//            else {
//                dp[i][j] = dp[i - 1][j]; // ��ǰ����������ѡ��ǰ��Ʒ����ѡ�����Ʒ
//            }
//        }
//    }
//    cout << dp[m][N] << endl; // �������ܼ�ֵ
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    vector<int> sizes; // ��Ʒ�ߴ�
//    sizes.resize(6);
//    for (int i = 0; i < sizes.size(); ++i) cin >> sizes[i];
//    int totalBoxes = 0; // ������
//    for (int i = 0; i < 6; i++) {
//        int currentSize = sizes[i];
//        int boxesNeeded = currentSize * currentSize / 36; // ������Ҫ������
//        if (currentSize * currentSize % 36 != 0) {
//            boxesNeeded++; // �����ʣ��ռ䣬��Ҫ���������
//        }
//        totalBoxes += boxesNeeded; // �ۼ�������
//    }
//    std::cout << "������Ҫ " << totalBoxes << " ������" << std::endl;
//    return 0;
//}