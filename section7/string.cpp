#include<iostream>
using namespace std;


//find length of a string
int str_len(char a[])
{
    int i=0;
    for(i=0; a[i] != '\0'; i++){}
    return i;
}

//change the case of the string
void case_change(char s[])
{
    int i=0; 
    while(s[i] != '\0')
    {
        if(s[i] >= 65 && s[i] <= 90)
        {
            s[i] += 32;
        }
        else if(s[i] >= 97 && s[i] <=122)
        {
            s[i] -= 32;
        }
        i++;
    }
    cout<<s<<endl;
}

//counting vowels and consonant in the string
void vow_cons(char s[])
{
    int vow=0,cons=0, word=0;
    for(int i=0; s[i] != '\0'; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' )
        {
            vow++;
        }
        if(s[i] == ' ' && s[i-1] != ' '){ word++; } //for counting number of words
    }
    cout<<"No of vowels: "<<vow<<endl;
    cout<<"No of consonant: "<<26-vow<<endl;
    cout<<"No of words in the string : "<<++word<<endl;
}

//check a valid string
//valid if only number and alphabets 
bool str_valid(char s[])
{
    for(int i=0; s[i] != '\0'; i++)
    {
        if(!(s[i] >= 65 && s[i] <=90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] >=48 && s[i] <= 57))
        {
            return false;
        }
    }
    return true;
}

//reversing a string 
void reverse_str(char s[])
{
    char b[10];
    int i;
    for(i=0; s[i] != '\0'; i++){};
    i--;
    int j;
    for(j=0; i >= 0; i--,j++)
    {
        b[j] = s[i];
    }
    b[j] = '\0';
    cout<<b<<endl;
}

//another method (without using another array)
void reverse_str2(char s[])
{
    int i,j;
    char t;
    for(j=0; s[j] != '\0'; j++){};
    j--;
    for(i=0; i<j; i++,j--)
    {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    cout<<s<<endl;
}

//comparing a string and find palindrome a string 
void str_compare(char a[], char b[])
{
    int i;
    for(i=0; a[i] != '\0' && b[i] != '\0'; i++)
    {
        if(a[i] != b[i])
            break;
    }
    if(a[i]==b[i])
    {
        cout<<"Both are same"<<endl;
    }
    else if(a[i] < b[i])
    {
        cout<<a<<" is smaller"<<endl;
    }else
    {
        cout<<a<<" is grater"<<endl;
    }
}

//check palindrome string 
bool str_isPalindrome(char s[])
{
    char b[100];
    int i,j;
    for (i=0; s[i] != '\0';i++){};
    i--;
    for(j=0; i>=0; j++,i--)
    {
        b[j] = s[i];
    }
    b[j] = '\0';
    //compare 
    for(int k=0; s[k] != '\0'; k++)
    {
        if(s[k] != b[k])
        {
            return 0;
        }
    }
    return 1;
}

//without using another array
bool isPalin(char a[])
{
    int i,j;
    for(j=0; a[j] != '\0'; j++){};
    j--;
    for(i=0; i<j; i++,j--)
    {
        if(a[i] != a[j])
            return 0;
    }
    return 1;
}

//finding duplicates in a string
//by compare each with other 
void str_duplicate(char s[])
{
    for(int i=0; s[i] != '\0'; i++)
    {
        int c=1;
        for(int j=i+1; s[j] != '\0'; j++)
        {
            if(s[i] == s[j] && s[i] != -1)
            {
                c++;
                s[j] = -1;
            }
        }
        if(c > 1)
        {
            cout<<s[i]<<" is duplicate"<<endl;
        }
    }
}

//using hash table 
void duplicate(char a[])
{
    int arr[26] = {0};   //only work for small letters
    for(int i=0; a[i] != '\0'; i++)
    {
        arr[a[i]-97]++; 
    }

    for(int j=0; j<26; j++)
    {
        if(arr[j] > 1)
        {
            cout<<(char)(j+97)<<" duplicate"<<endl;
        }
    }
}

//Finding duplicate using bit operations
void bit_dup(char a[])
{
    long int h=0,mask=0;
    for(int i=0; a[i] != '\0'; i++)
    {
        mask = 1;
        mask = mask << (a[i]-97);
        if((h & mask) > 0)
        {
            cout<<a[i]<<" duplicate"<<endl;
        }
        else
        {
            //set bit to one
            h = h | mask;
        }
    }
}

//checking Anagram string or not (two string with same set of characters are called anagrams)
bool str_anagram(char a[], char b[])
{
    int i,j,n=0;
    for(i=0;a[i] != '\0'; i++){};
    for(j=0;b[j] != '\0'; j++){};
    if(i != j)
    {
        return 0;
    }
    for(int k=0; k<i; k++)
    {
        for(int t=0; t<i; t++)
        {
            if(a[k] == b[t]){n++;};
        }
    }
    if(n == i)
    {
        return 1;
    }else
    {
        return 1;
    }
}

//checking a string is anagram or not (second method) using hashtable
bool anagram(char a[], char b[])
{
    int arr[128] = {0};
    for(int i=0; a[i] != '\0'; i++)
    {
        arr[a[i]-97]++;
    }
    for(int i=0; b[i] != '\0'; i++)
    {
        arr[b[i]-97]--;
    }
    for(int i=0; i<128; i++)
    {
        if(arr[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}


// bool anagram2(char a[], char b[])
// {
//     int i,arr[128] = {0};
//     for(i=0; a[i] != '\0'; i++)
//     {
//         arr[a[i]-97]++;
//     }
//     for(i=0; b[i] != '\0'; i++)
//     {
//         arr[b[i]-97]--;
//         if(arr[i] < 0)
//         {
//             return 0;
//         }
//     }
//     if(b[i] == '\0')
//     {
//         return 1;
//     }
// }


//performing permutation of the string meaning all possinble arrangements of the characters of the string
void perm(char s[],int k)
{
    static int a[10] = {0};
    static char res[10];
    int i;

    if(s[k] == '\0')
    {
        res[k] = '\0';
        cout<<res<<endl; 
    }else
    {
        for(i=0; s[i] != '\0'; i++)
        {
            if(a[i] == 0)
            {
                res[k] = s[i];
                a[i] = 1;
                perm(s,k+1);
                a[i] = 0;
            }
        }
    }
}

void perm2(char s[],int l,int h)
{
    int i;
    if(l==h)
    {
        cout<<s<<endl;
    }else
    {
        for(i=l; i<=h; i++)
        {
            swap(s[i] , s[l]);
            perm2(s,l+1,h);
            swap(s[i] , s[l]);
        }
    }
}

int main() 
{
    char name[100];
    // char name2[100];
    cin.getline(name,100);
    // cin.getline(name2,100);
    // cout<<str_len(name)<<endl;
    // case_change(name);
    // vow_cons(name);
    // cout<<str_valid(name)<<endl;
    // reverse_str(name);
    // reverse_str2(name);
    // str_compare(name,name2);
    // cout<<str_isPalindrome(name)<<endl;
    // cout<<isPalin(name)<<endl;
    // str_duplicate(name);
    // duplicate(name);
    // bit_dup(name);
    // cout<<str_anagram(name,name2)<<endl;
    // cout<<anagram(name,name2)<<endl;
    // cout<<anagram2(name,name2)<<endl;
    // perm(name,0);
    int n = str_len(name);
    perm2(name,0,n-1);
    // cout<<name<<endl;
    return 0;
}
