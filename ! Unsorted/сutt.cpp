#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define sizeVec(c) int((c).size())
#define all(c) (c).begin(),(c).end()
 
#define LENGTH(a)  ((*a).first) 
#define BEG(a)  ((*a).second.first) 
#define END(a)  ((*a).second.second)        
 
const int begDiapason = 0;
const int endDiapason = 100;
 
typedef  vector<pair< int, pair<int, int> > > SEGMENT;
int main()
{
    char *file="data.txt";
    int beg, end, counter=0;
    bool flag;
    SEGMENT arrSeg;
    SEGMENT::iterator itt;
 
    ifstream f(file);
    if (!(f.is_open()))  // проверка наличия первого файла с текстом
        cout<<"ERROR: not file "<<file;
    else
        while(!f.eof()) // чтении из файла
        {   
            f>>beg; f>>end;
            arrSeg.push_back(make_pair(end-beg, make_pair(beg, end)));
        }
 
 
    // вывод для отладки
    for (SEGMENT::iterator it=arrSeg.begin(); it<arrSeg.end(); it++)
        cout<<"length:"<<LENGTH(it)<<" beg:"<<BEG(it)<<" end:"<<END(it)<<endl;
    cout<<endl;
 
//  sort(all(arrSeg));  reverse(all(arrSeg));  // можно иначе
 
    beg=begDiapason; 
//  for (itt=arrSeg.begin(); itt<arrSeg.end(); itt++)
//     if (beg>=BEG(itt)) 
//      { beg=END(itt); break; }
// 
//  if(beg!=begDiapason) // если после первого поиска не обнаружен отрезок с begDiapason..Х
//  {
//      cout<<++counter<<". length:"<<LENGTH(itt)<<" beg:"<<BEG(itt)<<" end:"<<END(itt)<<endl;
//      arrSeg.erase(itt);
        
        while (!(arrSeg.empty()))
        {
            // достигли конца диапазона
            if (beg>=endDiapason) break;
            // подравниваем все отрезки под текущую позицию бегунка
            for (SEGMENT::iterator it=arrSeg.begin(); it<arrSeg.end(); it++)
                if (beg>BEG(it))    
                    { BEG(it)=beg; LENGTH(it)=END(it)-BEG(it); }
      // сортируем по убыванию (полезные длины отрезков поменялись)
            sort(all(arrSeg));  reverse(all(arrSeg)); 
 
            // ищем максимальный отрезок начинающийся с позиции бегунка
            flag=false;
            for (itt=arrSeg.begin(); itt<arrSeg.end(); itt++)
                if (beg>=BEG(itt)) 
                { flag=true; break; }
 
            if (flag==false) break;
            // если бегунок на отрезке длиной больше нуля
            // инкрементируем счётчик отрезков и по новой
            if (LENGTH(itt)>0)
            {
                cout<<++counter
                    <<". length:"<<LENGTH(itt)
                    <<" beg:"<<BEG(itt)
                    <<" end:"<<END(itt)<<endl;
                beg=END(itt);
                arrSeg.erase(itt);
            }
            else
                break;
        }
        
        if(beg>=endDiapason)
            cout<<"\nmin number segments: "<<counter;
        else
            cout<<"\nit cannot be done: ";
 
    f.close();  cout << endl;   system("PAUSE");
    return 0;
}