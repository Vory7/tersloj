#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
	int start;
	int end;
	int length;
};

bool compare(Node a, Node b)
{
	return a.length < b.length;
}

void Kraskal(vector<Node> &arr, vector<bool> &visited, int N1)
{
	int M, N;
	M = visited.size();
	N = arr.size();
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].start >> arr[i].end >> arr[i].length;
	}
	sort(arr.begin(), arr.end(), compare);
	int weight = 0;
	int r = 0;
	for (int i = 0; i < N; i++)
	{
		if (!visited[arr[i].start] || !visited[arr[i].end])
		{
			std::cout << "Берем ребро (" << arr[i].start << ',' << arr[i].end << ')' << std::endl;
			weight += arr[i].length;
			if (visited[arr[i].start] == false) r++;
			if (visited[arr[i].end] == false) r++;
			visited[arr[i].start] = true;
			visited[arr[i].end] = true;
			if(r == N1) break;
		} else
		{
			std::cout << "Не берем ребро (" << arr[i].start << ',' << arr[i].end << ')' << std::endl;
		}
	}
	 cout << "Минимальный вес связующего дерева:";
	cout << weight << endl;
}

int main()
{
	int M,N;
	cin>>M>>N;
	vector<Node> arr(N);
	vector<bool> visited(M);
	Kraskal(arr,visited,M);
}
