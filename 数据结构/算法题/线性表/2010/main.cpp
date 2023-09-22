/* 算法基本思想
 * 先做p对n求余数
 * 先交换[0, p-1]，然后交换[p, n-1]，最后交换[0, n-1]
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
#include <iostream>
#include <queue>

using namespace std;

int arr[1000];
int n, p;

int main()
{
    queue<int> Q;
    cin >> n;
    cin >> p;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    p = p % n;
    for (int i = 0; i < p / 2; i++)
    {
        swap(arr[i], arr[p - i - 1]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < (n - p) / 2; i++)
    {
        // cout << arr[p + i] << " " << arr[n - i - 1] << endl;
        swap(arr[p + i], arr[n - i - 1]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}