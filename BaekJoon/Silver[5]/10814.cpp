// 나이순 정렬 (10814) Silver[5]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

#define Fast_IO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int N;
typedef struct {
	int num;
	int age;
	string name;
}node;
vector<node> vec;

// Function
void insol();
bool compare(node a, node b);

// Main
int main(int argc, char** argv) {
	Fast_IO;

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N;

	int a;
	string n;
	for (int i = 0; i < N; i++) {
		cin >> a >> n;
		vec.push_back({ i, a, n });
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << vec[i].age << " " << vec[i].name << "\n";
	}

}

// sort compare
bool compare(node a, node b) {

	if (a.age < b.age) { return true; }
	else if (a.age == b.age) { return a.num < b.num; }
	else { return false; }

}