#include<iostream>
using namespace std;

int main()
{
    int *a, n, ch, x , i, j;

    cout<<"Enter the size of the array: ";
    cin>>n;

    a = new int[n];

    do
    {
        cout<<"_______Choose operation(Diagonal Matrix)______ "<<endl;
        cout<<"1. Create "<<endl;
        cout<<"2. Get Element "<<endl;
        cout<<"3. Set the Elements"<<endl;
        cout<<"4. Display Matrix"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter the Element of the matrix: "<<endl;
            for(i=1; i<=n; i++)
            {
                cin>>x;
                a[i-1] = x;
            }
            cout<<endl;
            break;
        case 2:
            cout<<"Enter index of the element: ";
            cin>>i>>j;
            if(i==j) cout<<a[i-1]<<endl;
            else cout<<0<<endl;

            break;
        case 3:
            cout<<"Enter position and element(i,j,x): ";
            cin>>i>>j>>x;
            if(i==j)
            {
                a[i-1] = x;
            }
            cout<<endl;
            break;
        case 4:
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    if(i==j) cout<<a[i-1]<<" ";
                    else cout<<0<<" ";
                }
                cout<<endl;
            }
            break;
        default:
            cout<<"Invalid choice!"<<endl;
            break;
        }
    } while (ch);
    
}