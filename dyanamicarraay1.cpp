#include<iostream>
using namespace std;+
class dynamic_array{
private :
    int *array;
    int size;
    int capacity;
public:
     int get_size(){
         return size;
     }
     int get_capacity(){
         return capacity;
     }
    dynamic_array(){
    array=new int[1];
    size=0;
    capacity=1;
    }
    ~dynamic_array(){
       delete[]array;
       size=0;
       capacity=0;
    }
    void resize(){
        int *temp=new int[size*2];
        for(int i=0;i<size;i++){
            temp[i]=array[i];
        }
        delete []array;
        array=temp;
        capacity=2*capacity;
    }
    void insertbyshift(int index,int value){
        if(size==capacity){
            resize();
        }
        if(index>=capacity || index<0){
                cout<<"memory not exist"<<endl;

        }
        for(int i=size;i>=index;i--)
        {
            array[i]=array[i-1];
        }
        array[index]=value;
        size++;

    }
    void insert_array(int index,int value){
        if(size==capacity){
            resize();
        }
        if(index>=capacity || index<0){
                cout<<"memory not exist"<<endl;

        }
        array[index]=value;
        size++;
    }
     void print_array(){
         for(int i=0;i<size;i++){
            cout<<array[i]<<" ";
         }
          cout<<endl;
        cout<<" size = "<<size<<" capacity = "<<capacity<<endl;
     }
     void deletea( int index){
         if(index>=size)
         {
             cout<<" index does not exist "<<endl;
             return;
         }
         for(int i=index;i<size-1;i++){
            array[i]=array[i+1];
         }
         size--;

     }
      void shrink_to_fit(){
          int *temp=new int[size];
          for(int i=0;i<size;i++){
            temp[i]=array[i];
          }
          delete []array;
          array=temp;
          capacity=size;

      }
    int  search(int value){
        for(int i=0;i<size;i++){
                if(array[i]==value)
                return i;//value does not exist

        }
        return -1;
      }

};
int main(){
    dynamic_array a;
    cout<<" size = "<<a.get_size()<<" capacity = "<<a.get_capacity()<<endl;
    a.insert_array(0,10);
    a.print_array();

    a.insert_array(1,20);
    a.print_array();

    a.insert_array(2,30);
    a.print_array();

    a.insert_array(3,40);
    a.print_array();

    a.insert_array(4,50);
    a.print_array();

    a.insertbyshift(2,100);
    a.print_array();

    a.deletea(2);
    a.print_array();

    a.shrink_to_fit();
    a.print_array();

    int i=a.search(100);
    if(i!=-1){
        cout<<" value found "<<endl;
    }
    else{
        cout<<" value not found "<<endl;
    }


return 0;
}
