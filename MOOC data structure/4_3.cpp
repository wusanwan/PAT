#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
struct boundary{
    int a, b;
    boundary(int x,int y){
        a = x;
        b = y;
	}
};
queue<boundary> bound;
int FillBST(){
    boundary now = bound.front();//边界是[a,b]
    int num = now.b - now.a + 1;//结点数
    int floornum = ceil(log2(num+1));//层数
    int last_floor_node = num - pow(2, floornum-1) + 1;//最下面一层结点数
    int last_floor_fill = pow(2, floornum - 1);//最下一层可填充结点数
    int left_num, right_num;//左右子树结点数
    if(last_floor_fill>=last_floor_node*2){
        right_num = (num - 1 - last_floor_node) / 2;
        left_num = num - 1 - right_num;
    }
    else{
        left_num = pow(2, floornum - 1) - 1;
        right_num = num - 1 - left_num;
    }
    int result = now.a + left_num;
    boundary left(now.a, result - 1);
    boundary right(result + 1, now.b);
    bound.push(left);
    bound.push(right);
    bound.pop();
    return result;
}
int main(){
    int N,temp;
    vector<int> element;
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> temp;
        element.push_back(temp);
    }
    sort(element.begin(),element.end());
    boundary t(0,N-1);
    bound.push(t);
    for (int i = 0; i < N;i++){
        if(i)cout << " ";
        cout << element[FillBST()];
    }
	system("pause");
	return 0;
}