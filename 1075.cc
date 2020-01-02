#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct student{
    int id;
    int total_score;
    int grade[5];
    int rank;
    int full_score_question;
    int flag;//标识是否没有提交答案或者所有提交的答案都无法编译通过
};
int cmp(student a,student b){
    if(a.total_score!=b.total_score){
        return a.total_score>b.total_score;
    }else if(a.full_score_question!=b.full_score_question){
        return a.full_score_question>b.full_score_question;
    }else{
        return a.id<b.id;
    }
}
int main()
{
    int n,k,m;
    student st[10001];
    cin>>n>>k>>m;
    int full_mark[5]={-1};
    for(int i=0;i<k;++i){
        cin>>full_mark[i];
    }
    for(int i=0;i<=n;++i){
        st[i].id=-1;
        st[i].total_score=0;
        st[i].rank=0;
        st[i].full_score_question=0;
        st[i].flag=0;
        for(int j=0;j<5;++j){
            st[i].grade[j]=-2;
        }
    }
    for(int i=0;i<m;++i){
        int id,question,score;
        cin>>id>>question>>score;
        if(st[id].grade[question-1]<score){
            st[id].grade[question-1]=score;
        }
    }
    for(int i=1;i<=n;++i){
        st[i].id=i;
        for(int j=0;j<k;++j){
            if(st[i].grade[j]!=-1&&st[i].grade[j]!=-2){
                st[i].flag++;
                st[i].total_score+=st[i].grade[j];
            } 
            if(st[i].grade[j]==full_mark[j]){
                st[i].full_score_question++;
            }
        }
    }
    sort(st+1,st+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(st[i].total_score!=st[i-1].total_score){
            st[i].rank=i;
        }else{
            st[i].rank=st[i-1].rank;
        }
    }
    for(int i=1;i<=n;i++){
        if(st[i].flag){
            printf("%d %05d %d",st[i].rank,st[i].id,st[i].total_score);
            for(int j=0;j<k;j++){
                if(st[i].grade[j]>=0) {
                    printf(" %d",st[i].grade[j]);
                }else if(st[i].grade[j]==-2){
                    printf(" -");
                }else{
                    printf(" 0");
                }
            }
            if(i!=n) printf("\n");
        }
    }

    return 0;
}

