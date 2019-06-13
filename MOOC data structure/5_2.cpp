#include<iostream>

using namespace std; 
int find(int root[], int index){
	while (root[index] >0){//需注意的是如果第一次其根为-1，那么return的值应该是自己
		index = root[index];
	}
	return index;
}
int main(){
	int N,c1,c2;
	cin >> N;
	int root[10001];
	for (int i = 1; i <= N; i++)root[i] = -1;
	char type;
	cin >> type;
	while (type != 'S'){
		cin >> c1 >> c2;
		if (type == 'C'){//查
			if (find(root,c1) == find(root,c2))cout << "yes" << endl;
			else cout << "no" << endl;
		}
		else{//增
			int root1 = find(root, c1);
			int root2 = find(root, c2);
			if (root2 != root1){
				if (root[root2] > root[root1]){
					root[root1] += root[root2]; //更新组合内元素个数
					root[root2] = root1;
				}
				else{
					root[root2] += root[root1]; //更新组合内元素个数
					root[root1] = root2;
				}
			}
		}
		cin >> type;
	}
	int count=0;
	for (int i = 1; i <= N; i++){
		if (root[i] < 0)count++;
	}
	if (count == 1)cout << "The network is connected." << endl;
	else cout << "There are " << count << " components." << endl;
	system("pause");
	return 0;
}