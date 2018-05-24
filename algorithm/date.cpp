#include <iostream>
using namespace std;
bool finish_or_not(int, int *);
bool current_male_is_better(int num, int *male_rank_in_female, int current,
                            int chasing);
int main() {
    int num = 5;

    int female_rank_in_male[5][5] = {{2, 1, 4, 5, 3},
                                     {4, 2, 1, 3, 5},
                                     {2, 5, 3, 4, 1},
                                     {1, 4, 3, 2, 5},
                                     {2, 4, 1, 5, 3}};
    int male_rank_in_female[5][5] = {{5, 1, 2, 4, 3},
                                     {3, 2, 4, 1, 5},
                                     {2, 3, 4, 5, 1},
                                     {1, 5, 4, 3, 2},
                                     {4, 2, 5, 3, 1}};

    for (int i = 0; i < num; i++) {
        cout << "男生 " << i << " 心目中妹子的排行：";
        for (int j = 0; j < num; j++) {
            cout << female_rank_in_male[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < num; i++) {
        cout << "女生 " << i << " 心目中男生的排行：";
        for (int j = 0; j < num; j++) {
            cout << male_rank_in_female[i][j] << " ";
        }
        cout << endl;
    }

    //男生和妹子正在约会的对象
    int *date_of_male   = new int[num];
    int *date_of_female = new int[num];
    for (int i = 0; i < num; i++) {
        date_of_male[i]   = 0;
        date_of_female[i] = 0;
    }

    //男生追求过的妹子的数量
    int *num_of_chased_female = new int[num];
    for (int i = 0; i < num; i++) {
        num_of_chased_female[i] = 0;
    }

    do {                                 //如果有男生没有对象
        for (int i = 0; i < num; i++) {  //按序号遍历所有男生
            cout << endl
                 << "正在查看男生 " << i + 1 << " 有没有对象..." << endl;
            if (date_of_male[i] == 0) {  //如果某男生没有对象
                cout << "男生 " << i + 1 << " 没有对象！" << endl;
                //该男生准备追的妹子（该男生优先表中还没追求过的排名最高的妹子）
                int female_to_chase =
                    female_rank_in_male[i][num_of_chased_female[i]];
                //该男生准备追的妹子的现任
                int date_of_female_to_chase =
                    date_of_female[female_to_chase - 1];
                cout << "男生 " << i + 1 << " 准备追妹子 " << female_to_chase;
                if (date_of_female_to_chase != 0) {
                    cout << "，妹子现任是 " << date_of_female_to_chase << endl;
                } else {
                    cout << "，妹子目前是单身的呢~" << endl;
                }

                if (date_of_female_to_chase ==
                    0) {  //如果该男生准备追的妹子没有现任
                    date_of_male[i] =
                        female_to_chase;  //该男生的对象变成准备追的妹子
                    date_of_female[female_to_chase - 1] =
                        i + 1;  //男生准备追的妹子的对象变成该男生
                    cout << "这样子的话，男生 " << i + 1 << " 和妹子 "
                         << female_to_chase << " 在一起了！" << endl;
                } else if (current_male_is_better(
                               num, male_rank_in_female[female_to_chase - 1],
                               date_of_female_to_chase, i + 1)) {
                    //如果该男生准备追的妹子的现任在妹子心目中比该男生更好，则什么也不做
                    cout << "所以！男生 " << i + 1 << " 被妹子 "
                         << female_to_chase << " 拒绝了！" << endl;
                } else {  //如果该男生比该男生准备追的妹子的现任在妹子心目中更好
                    date_of_male[date_of_female_to_chase - 1] =
                        0;  //该男生准备追的妹子的现任回到单身状态
                    date_of_male[i] =
                        female_to_chase;  //该男生的对象变成准备追的妹子
                    date_of_female[female_to_chase - 1] =
                        i + 1;  //该男生准备追的妹子的对象变成该男生
                    cout << "所以！男生 " << i + 1 << " 和妹子 "
                         << female_to_chase << " 在一起了！" << endl;
                    cout << "与此同时，不幸的是，男生 "
                         << date_of_female_to_chase << " 变成单身狗了QAQ"
                         << endl;
                }

                num_of_chased_female[i]++;  //该男生追过的妹子数量加1
            } else {
                cout << "男生已经跟妹子 " << date_of_male[i]
                     << " 在一起了呢~~下一个吧~~~" << endl;
            }
        }
    } while (finish_or_not(num, date_of_male) == false);

    //最后的输出
    cout << endl << "┌───故事的结局───┐" << endl;
    cout << "│                      │" << endl;
    for (int i = 0; i < num; i++) {
        cout << "│     男生" << i + 1 << " - "
             << "女生" << date_of_male[i] << "    │" << endl;
        ;
    }

    cout << "│                      │" << endl;
    cout << "└───────────┘" << endl << endl;
    delete[] date_of_male;
    delete[] date_of_female;
    delete[] num_of_chased_female;
    system("pause");
    return 0;
}

bool finish_or_not(int num, int *date_of_male){

   for (int i = 0; i < num; i++){
       if (date_of_male[i] == 0){
           cout << "还有单身狗......再来~" << endl;
           return false;
       }
   }
   cout << endl << "已全部脱离单身狗行列！！！" << endl;
   return true;
}

//比较某妹子现在的对象和追求者哪个在她心目中排行更高
//注意数组参数是一维（一位妹子的优先表而不是所有妹子的优先表）
bool current_male_is_better(int num, int *male_rank_in_female, int current, int chasing){
   int rank_of_current, rank_of_chasing;
   for (int i = 0; i < num; i++){
       if (male_rank_in_female[i] == current){
           rank_of_current = i;
       }
       if (male_rank_in_female[i] == chasing){
           rank_of_chasing = i;
       }
   }
   cout << "在妹子心目中现任排名是 " << rank_of_current << " ，而追求者排名则是 " << rank_of_chasing << endl;
   if (rank_of_current < rank_of_chasing)
       return true;
   else
       return false;
}
