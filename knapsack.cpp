#include<cstdio>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;
int m, n;
const int MAX_SLICES = 1e9+5;
int slices[100005];
unordered_map<int, bool> f;
unordered_map<int,int> path,pathType;
vector<int> save;
void saveResult(int ans) {
	save.clear();
	stack<int> s;
	s.push(pathType[ans]);
	int cur = ans;
	while (cur) {
		cur = path[cur];
		s.push(pathType[cur]);
	}
	while (!s.empty()) {
		save.push_back(s.top());
		s.pop();
	}
}
int main() {
	int maxM = 0;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)scanf("%d", &slices[i]);
	f[0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= slices[i]; j--) {
			if (!f[j] && f[j - slices[i]]) {
				f[j] |= f[j - slices[i]];
				path[j] = j - slices[i];
				pathType[j] = i;
			}
		}
	}
	for (int i = m; i >= 0; i--)if (f[i]) {
		saveResult(i);
		break;
	}
	if (save.size() == 1) {
		printf("0");
	}
	else {
		printf("%d\n", save.size()-1);
		for (int i = 1; i < save.size(); i++)printf("%d ", save[i]-1);
	}
}
