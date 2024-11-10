#include <iostream>
#include <iomanip>
#include <fstream>
#define MAX 100
using namespace std;

class Blooms_Level{
    private:
        int id;
        string blooms_code;
        string blooms_level;
        string blooms_description;
        static Blooms_Level blooms_level_list[MAX];
        static int length;
    public:
        static void _404Error_blooms_level_create(){
            Blooms_Level blooms_level_element;
            cout<<"\nEnter ID: ";
            cin>>blooms_level_element.id;
            cout<<"Enter Blooms Code: ";
            cin>>blooms_level_element.blooms_code;
            cout<<"Enter Blooms Level: ";
            cin>>blooms_level_element.blooms_level;
            cout<<"Enter Blooms Desription: ";
            cin>>blooms_level_element.blooms_description;
            blooms_level_list[length]=blooms_level_element;
            length++;
            cout<<"Blooms Level Created\n\n";
        }
        static void _404Error_blooms_level_update(){
            int update_id;
            cout<<"\nEnter ID to update: ";
            cin>>update_id;
            for(int i=0;i<length;i++){
                if(blooms_level_list[i].id==update_id){
                    cout<<"Update Blooms Code: ";
                    cin>>blooms_level_list[i].blooms_code;
                    cout<<"Update Blooms Level: ";
                    cin>>blooms_level_list[i].blooms_level;
                    cout<<"Update Blooms Desription: ";
                    cin>>blooms_level_list[i].blooms_description;
                    cout<<"Blooms Level Updated\n\n";
                    return;
                }
            }
            cout<<"ID Not Found\n\n";
        }
        static void _404Error_blooms_level_retrieve(){
            int retrieve_id;
            cout<<"\nEnter ID to retrieve: ";
            cin>>retrieve_id;
            for(int i=0;i<length;i++){
                if(blooms_level_list[i].id==retrieve_id){
                    cout<<"ID: "<<blooms_level_list[i].id<<"\n";
                    cout<<"Blooms Code: "<<blooms_level_list[i].blooms_code<<"\n";
                    cout<<"Blooms Level: "<<blooms_level_list[i].blooms_level<<"\n";
                    cout<<"Blooms Description: "<<blooms_level_list[i].blooms_description<<"\n\n";
                    return;
                }
            }
            cout<<"ID Not Found\n\n";
        }
        static void _404Error_blooms_level_delete(){
            int delete_id;
            cout<<"\nEnter ID to delete: ";
            cin>>delete_id;
            for(int i=0;i<length;i++){
                if(blooms_level_list[i].id==delete_id){
                    for(int j=i;j<length-1;j++){
                        blooms_level_list[j]=blooms_level_list[j+1];
                    }
                    length--;
                    cout<<"Element Deleted\n\n";
                    return;
                }
            }
            cout<<"ID Not Found\n\n";
        }
        static void _404Error_blooms_level_bubble_sort(){
            int choice;
            cout<<"\nChoose Column To Sort:\n1|Blooms ID\n2|Blooms Code\n3|Blooms Level\nChoose: ";
            cin>>choice;
            switch(choice){
            case 1:
                for(int i=0;i<length-1;i++){
                    for(int j=0;j<length-i-1;j++){
                        if(blooms_level_list[j].id>blooms_level_list[j+1].id){
                            Blooms_Level temp=blooms_level_list[j];
                            blooms_level_list[j]=blooms_level_list[j+1];
                            blooms_level_list[j+1]=temp;
                        }
                    }
                }
                break;
            case 2:
                for(int i=0;i<length-1;i++){
                    for(int j=0;j<length-i-1;j++){
                        if(blooms_level_list[j].blooms_code>blooms_level_list[j+1].blooms_code){
                            Blooms_Level temp=blooms_level_list[j];
                            blooms_level_list[j]=blooms_level_list[j+1];
                            blooms_level_list[j+1]=temp;
                        }
                    }
                }
                break;
            case 3:
                for(int i=0;i<length-1;i++){
                    for(int j=0;j<length-i-1;j++){
                        if(blooms_level_list[j].blooms_level>blooms_level_list[j+1].blooms_level){
                            Blooms_Level temp=blooms_level_list[j];
                            blooms_level_list[j]=blooms_level_list[j+1];
                            blooms_level_list[j+1]=temp;
                        }
                    }
                }
                break;
            default:cout<<"Invalid Choice\n\n";
            }

        }
        static void _404Error_blooms_level_linear_search(){
            int choice;
            string search_value;
            bool found=false;
            cout<<"\nChoose Column To Search:\n1|Blooms Code\n2|Blooms Level\nChoose: ";
            cin>>choice;
            cout<<"Enter the value to search: ";
            cin>>search_value;
            switch(choice){
                case 1:
                    for(int i=0;i<length;i++){
                        if(blooms_level_list[i].blooms_code==search_value){
                            cout<<"ID: "<<blooms_level_list[i].id<<"\n";
                            cout<<"Blooms Code: "<<blooms_level_list[i].blooms_code<<"\n";
                            cout<<"Blooms Level: "<<blooms_level_list[i].blooms_level<<"\n";
                            cout<<"Blooms Description: "<<blooms_level_list[i].blooms_description<<"\n\n";
                            found=true;
                        }
                    }
                    if(!found){
                        cout<<"Value Not Found\n\n";
                    }
                    break;
                case 2:
                    for(int i=0;i<length;i++){
                        if(blooms_level_list[i].blooms_level==search_value){
                            cout<<"ID: "<<blooms_level_list[i].id<<"\n";
                            cout<<"Blooms Code: "<<blooms_level_list[i].blooms_code<<"\n";
                            cout<<"Blooms Level: "<<blooms_level_list[i].blooms_level<<"\n";
                            cout<<"Blooms Description: "<<blooms_level_list[i].blooms_description<<"\n\n";
                            found=true;
                        }
                    }
                    if(!found){
                        cout<<"Value Not Found\n\n";
                    }
                    break;
                default:cout<<"Invalid Choice\n\n";
            }
        }
        static void _404Error_blooms_level_storing(){
            ofstream outFile("blooms_level.txt");
            if(outFile.is_open()){
                for(int i=0;i<length;i++){
                    outFile<<blooms_level_list[i].id<<" "
                           <<blooms_level_list[i].blooms_code<<" "
                           <<blooms_level_list[i].blooms_level<<" "
                           <<blooms_level_list[i].blooms_description<<"\n";
                }
                outFile.close();
                cout<<"Data stored successfully.\n\n";
            }
            else{
                cout<<"Unable to open file for writing.\n\n";
            }
        }
        static void _404Error_blooms_level_compare_sorting_bubble_sort(){
            _404Error_blooms_level_complexity_sorting();
            _404Error_blooms_level_bubble_sort_details();
        }
        static void _404Error_blooms_level_compare_searching_linear_search(){
            _404Error_blooms_level_complexity_searching();
            _404Error_blooms_level_linear_search_details();
        }
        static void _404Error_blooms_level_complexity_sorting(){
            cout<<"\nBubble Sort Time Complexity:\nO(n^2)\nΩ(n)\nΘ(n^2)\n";
            cout<<"\nQuick Sort Time Complexity:\nO(n^2)\nΩ(nlog(n))\nΘ(nlog(n))\n\n";
        }
        static void _404Error_blooms_level_complexity_searching(){
            cout<<"\nLinear Search Time Complexity:\nO(n)\nΩ(1)\nΘ(n)\n";
            cout<<"\nBinary Search Time Complexity:\nO(log(n))\nΩ(1)\nΘ(log(n))\n\n";
        }
        static void _404Error_blooms_level_bubble_sort_details(){
            cout<<"\nBubble Sort Algorithm:\nbubbleSort(array)\n  for i <- 1 to sizeOfArray - 1\n    swapped <- false\n    for j <- 1 to sizeOfArray - 1 - i\n      if leftElement > rightElement\n        swap leftElement and rightElement\n        swapped <- true\n    if swapped == false\n      break\nend bubbleSort\n";
            cout<<"\nQuick Sort Time Complexity:\nquickSort(array, leftmostIndex, rightmostIndex)\n  if (leftmostIndex < rightmostIndex)\n    pivotIndex <- partition(array,leftmostIndex, rightmostIndex)\n    quickSort(array, leftmostIndex, pivotIndex - 1)\n    quickSort(array, pivotIndex, rightmostIndex)\npartition(array, leftmostIndex, rightmostIndex)\n  set rightmostIndex as pivotIndex\n  storeIndex <- leftmostIndex - 1\n  for i <- leftmostIndex + 1 to rightmostIndex\n  if element[i] < pivotElement\n    swap element[i] and element[storeIndex]\n    storeIndex++\n  swap pivotElement and element[storeIndex+1]\nreturn storeIndex + 1\n\n";
        }
        static void _404Error_blooms_level_linear_search_details(){
            cout<<"\nLinear Search Algorithm:\nLinearSearch(array, key)\n  for each item in the array\n    if item == value\n      return its index\n";
            cout<<"\nBinary Search Algorithm:\nbinarySearch(arr, x, low, high)\n    if low > high\n        return False\n    else\n        mid = (low + high) / 2\n        if x == arr[mid]\n            return mid\n        else if x > arr[mid]\n            return binarySearch(arr, x, mid + 1, high)\n        else\n            return binarySearch(arr, x, low, mid - 1)\n\n";
        }
        static void _404Error_blooms_level_load(){
            ifstream inFile("blooms_level.txt");
            if(inFile.is_open()){
                length=0;
                string line;
                while(getline(inFile,line)){
                    istringstream iss(line);
                    Blooms_Level blooms_level_element;
                    if(!(iss>>blooms_level_element.id>>blooms_level_element.blooms_code>>blooms_level_element.blooms_level)){
                        break;
                    }
                    iss.ignore();
                    getline(iss,blooms_level_element.blooms_description);
                    blooms_level_list[length]=blooms_level_element;
                    length++;
                }
                inFile.close();
                cout<<"Data loaded successfully.\n";
            }
            else{
                cout<<"Unable to open file for reading.\n";
            }
        }
        static void _404Error_blooms_level_display_table(){
            if(length==0){
                cout<<"Blooms Level Table Empty\n\n";
                return;
            }
            cout<<"\nBlooms Levels Table:\n";
            cout<<setw(10)<<left<<"ID"
                <<setw(20)<<left<<"Blooms Code"
                <<setw(20)<<left<<"Blooms Level"
                <<setw(50)<<left<<"Blooms Description"<<"\n";
            cout<<"--------------------------------------------------------------------------------\n";
            for(int i=0;i<length;i++){
                cout<<setw(10)<<left<<blooms_level_list[i].id
                    <<setw(20)<<left<<blooms_level_list[i].blooms_code
                    <<setw(20)<<left<<blooms_level_list[i].blooms_level
                    <<setw(50)<<left<<blooms_level_list[i].blooms_description << "\n";
            }
            cout<<"--------------------------------------------------------------------------------\n";
        }
        static void _404Error_blooms_level_line(){
            cout<<"________________________________________________________________________________\n";
        }
};





Blooms_Level Blooms_Level::blooms_level_list[MAX];
int Blooms_Level::length=0;

int main(){
    int choice;
    Blooms_Level::_404Error_blooms_level_load();
    while(true){
        cout<<"Blooms Level\nChoose an option:\n1| Create\n2| Update\n3| Retrieve\n4| Delete\n5| Sorting\n6| Searching\n7| Storing\n8| Comparision Sorting\n9| Comparision Searching\n10| Time Complexity Sorting\n11| Time Complexity Searching\n12| Algorithm Details Sorting\n13| Algorithm Details Searching\n14| Display\n15|Exit\nChoice: ";
        cin>>choice;
        Blooms_Level::_404Error_blooms_level_line();
        switch(choice){
            case 1:Blooms_Level::_404Error_blooms_level_create();break;
            case 2:Blooms_Level::_404Error_blooms_level_update();break;
            case 3:Blooms_Level::_404Error_blooms_level_retrieve();break;
            case 4:Blooms_Level::_404Error_blooms_level_delete();break;
            case 5:Blooms_Level::_404Error_blooms_level_bubble_sort();break;
            case 6:Blooms_Level::_404Error_blooms_level_linear_search();break;
            case 7:Blooms_Level::_404Error_blooms_level_storing();break;
            case 8:Blooms_Level::_404Error_blooms_level_compare_sorting_bubble_sort();break;
            case 9:Blooms_Level::_404Error_blooms_level_compare_searching_linear_search();break;
            case 10:Blooms_Level::_404Error_blooms_level_complexity_sorting();break;
            case 11:Blooms_Level::_404Error_blooms_level_complexity_searching();break;
            case 12:Blooms_Level::_404Error_blooms_level_bubble_sort_details();break;
            case 13:Blooms_Level::_404Error_blooms_level_linear_search_details();break;
            case 14:Blooms_Level::_404Error_blooms_level_display_table();break;
            case 15:return 0;
            default:cout<<"Invalid choice. Try again.\n";
        }
        Blooms_Level::_404Error_blooms_level_line();
    }
    Blooms_Level::_404Error_blooms_level_storing();
    return 0;
}