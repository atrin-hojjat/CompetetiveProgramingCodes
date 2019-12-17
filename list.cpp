#include <iostream>
#include <iomanip>

using namespace std;

namespace __nn_list__ {
    
#define INDEX_OUT_OF_RANGE -1
    
    template <class T> struct __nn_list_node;
    template <class T> struct __nn_list;
    template <class T>__nn_list<T> init();
    template <class T>__nn_list_node<T>* at(__nn_list_node<T> *node,int pos);
    template <class T>__nn_list_node<T>* at(__nn_list<T> *list,int pos);
    template <class T>T at_val(__nn_list<T> *list,int pos);
    template <class T>void add(__nn_list<T> *list,T val,unsigned int pos);
    template <class T>void __nn_list_print(__nn_list<T> *list);
    template <class T> void __nn_recalc_size(__nn_list<T> *list);

    //NODE
    
    template <class T>struct __nn_list_node {
        T val;
        __nn_list_node *next;
    };
    
    //LIST
    
    template <class T>struct __nn_list {
        __nn_list_node<T> *nodes;
        int size = 0;
        void operator << (T val) {add(this,val,size);}
        T operator >> (unsigned int pos) {return pos<size ? at_val(this,pos) : NULL;}
    };
    
    //INIT
    
    template <class T>__nn_list<T> init(){
        return __nn_list<T>();
    }
    
    //AT
    
    template <class T>__nn_list_node<T>* at(__nn_list_node<T> *node,int pos){
        if(pos == 0){
            return node;
        }
        else if(node->next == NULL){
            throw INDEX_OUT_OF_RANGE;
            return NULL;
        }
        else 
            return at<T>(node->next,pos-1);
    }
    template <class T>__nn_list_node<T>* at(__nn_list<T> *list,int pos){
        return at<T>(list->nodes,pos);
    }
    
    //AT VAL
    template <class T>T at_val(__nn_list<T> *list,int pos){
        return at<T>(list->nodes,pos)->val;
    }

    template <class T>void add(__nn_list<T> *list,T val,unsigned int pos){
        if(pos == 0){
            __nn_list_node<T> node;
            node.val =val;
            __nn_list_node<T> *ptr = list->nodes;
            // cout << node.next <<" " << ptr <<" "<< list->nodes<<endl;
            if(ptr){node.next = ptr;cout << ptr->val << endl;}
            else node.next = NULL;
            list->nodes = &node;
            // cout << node.next <<" " << ptr <<" "<< list->nodes<<endl;
            cout << list->nodes << endl;
            if(list->nodes->next) cout<<list->nodes->next->val << endl;
            list->size++;
        }else{
            __nn_list_node<T> *prev = at<T>(list,pos-1);
            __nn_list_node<T> node;
            __nn_list_node<T>*ptr = prev->next;
//            if(prev)cout << prev->val <<endl;else return;
            node.val = val;
            node.next = ptr;
            prev->next = &node;
            cout << prev<< " " << prev->next << " " << list->nodes->next <<endl;
            list->size++;
            __nn_list_print (list);
        }
    }
    
    template <class T>void __nn_list_print(__nn_list<T> *list){
        __nn_list_node<T> node = * (list->nodes);
        int indexer = 0;
        if(list->size<=0)return;
        cout << list->nodes <<endl;
        cout << indexer+1 << " : "<< node.val << endl;
        while(++indexer <list->size) {
            cout << indexer << " " << list->size << endl;
            cout << node.next << endl;
            node = *(node.next);
            cout << indexer+1 << " : "<< node.val << endl;
        }
    }
    
    template <class T> void __nn_recalc_size(__nn_list<T> *list){
        __nn_list_node<T> *node = list->nodes;
        int size = 0;
        while(node){
            size++;
            node = node->next;
        }
    }
#undef INDEX_OUT_OF_RANGE
}


int main(){
    __nn_list__::__nn_list<int> list = __nn_list__::init<int>();
   __nn_list__::add<int>(&list,10,0);
   cout << list.nodes << endl;
   __nn_list__::add<int>(&list,20,1);
   cout << list.nodes << " "<< list.nodes->next<< endl;
   cout << endl <<endl;
//    __nn_list__::add<int>(&list,20,2);
//    __nn_list__::__nn_recalc_size(&list);
    // list << 10 ;list<< 20;
    // std::cout<<list.size<<std::endl;
    cout << list.nodes << " " << __nn_list__::at<int>(&list,1) <<endl;
    cout << endl <<endl;
    // cout << (list>>0) << " " << (list>> 1) <<endl;
    __nn_list__::__nn_list_print (&list);
    cout << endl << endl;
    return 0;
}



