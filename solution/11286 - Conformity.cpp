#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int t, val, maks, cnt;
map<vector<int>, int> student;
vector<int> course;

int main(){
    while(true){
        scanf("%d", &t);
        if(t == 0)
            break;

        cnt = 0;
        maks = 1;

        student.clear();

        while(t--){
            course.clear();
            for(int i = 0; i < 5; i++){
                scanf("%d", &val);
                course.push_back(val);
            }
            sort(course.begin(), course.end());
            if(student.count(course) == 0){
                student.insert(pair<vector<int>, int>(course, 1));
            }
            else{
                student[course] += 1;
                if(student[course] > maks) maks = student[course];
            }
        }

        for(map<vector<int>, int>::iterator it = student.begin(); it != student.end(); ++it){
            if(it->second == maks) cnt+=maks;
        }

        printf("%d\n", cnt);
    }
}
