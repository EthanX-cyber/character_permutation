/*Permutation of Inputted Character*/
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
static long long int check = 0;
static int pri = 0;
static string filesave;
int pr(char* arr, int i, string s, int len)
{
    if (i == 0) // when length has been reached
        {
            check ++;
            if((pri == 1)||(pri == 3))
                cout << s << endl;

            if((pri == 2)||(pri == 3))
                {
                    char p = '\n';
                    s.push_back(p);
                    string filename(filesave);
                    fstream file;

                    file.open(filename,ios_base::app);
                    if (file.is_open())
                    file.write(s.data(), s.size());
                }

            return 0;
        }

    for (int j = 0; j < len; j++) // permutation block
        {
            string appended = s + arr[j];
            pr(arr, i - 1, appended, len);
        }

    return check;
}

// function to print and limit all possible permutation
int perm(char* arr,int len,int in,int out)
{
    long long int check;
    for (int i = in; i <= out; i++) // limiter
        check = pr(arr, i, "", len);
    return check;
}


int main()
{
    int in,out,arrsize;
    cout << "Enter the Minimum Length : ";
    cin >> in;
    cout << "Enter the Maximum Length : ";
    cin >> out;
    cout << "Enter the Array Size : ";
    cin >> arrsize;
    char arr[arrsize];
    cout << "Enter the List: ";
    for(int i=0;i<arrsize;i++)
        cin >> arr[i];
    cout << "Print Option (0- Nothing / 1- Console / 2- File / 3- Both): ";
    cin >> pri;
    if((pri == 2)||(pri == 3))
    {
        cout << "Enter the File Name : ";
        cin >> filesave;
        cout << "Check program file directory for the save file";
        filesave.append(".txt");
    }
    cout << endl << "Inputted Character List : ";
    for(int i=0;i<arrsize;i++)
        cout << arr[i] << " ";

    cout << endl <<"All Possible Permutation : " << endl;
  //  int len = sizeof(arr) / sizeof(arr[0]);
    long long int check = perm(arr,arrsize,in,out);
    cout << endl <<"No of Permutations : "<< check << endl;
    return 0;
}
