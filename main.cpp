#include "function.h"
/*
 * 41．（13 分）二叉树的带权路径长度（WPL）是二叉树中所有叶结点的带权路径长度
    之和。给定一棵二叉树 T，采用二叉链表存储，结点结构如下：
    left weight right
    其中叶结点的 weight 域保存该结点的非负权值。设 root 为指向 T 的根结点的指针，请设计
    求 T 的 WPL 的算法，要求：
    1）给出算法的基本设计思想。
    2）使用 C 或 C++语言，给出二叉树结点的数据类型定义。
    3）根据设计思想，采用 C 或 C++语言描述算法，关键之处给出注释。
  树的带权路径长度(Weighted Path Length of Tree),简记为WPL
  二叉树的带权路径长度，二叉树的带权路径长度为每个叶子结点的深度与权值之积的总和
 * */
int wpl=0;

void PreOrder(BiTree root,int deep){
//    static int wpl=0;//wpl为静态局部变量(存储在数据区)，类似于全局变量，只会初始化一次
        if(root->lchild==NULL&&root->rchild==NULL){//若为叶子结点，累积wpl
            wpl+=deep*root->weight;
        }
        if(root->lchild!=NULL){
            PreOrder(root->lchild,deep+1);
        }
        if(root->rchild!=NULL){
            PreOrder(root->rchild,deep+1);
        }
//    return wpl;
}
int main(){
    BiTree pnew;//用于存储新的树结点
    BiTree tree=NULL;//树根
    ptag_t phead=NULL,ptail=NULL,list_pnew=NULL,pcur;//phead就是队列头，ptail就是队列尾，pcur始终指向要插入的结点的位置
    char c;
    while(scanf("%c",&c)){//输入abcdefghij
        if(c=='\n'){
            break;
        }
        //calloc申请空间并对空间进行初始化，赋值为0
        pnew=(BiTree) calloc(1,sizeof(BiTNode));
        pnew->weight=c;//数据放进去
        list_pnew=(ptag_t) calloc(1,sizeof(ptag_t));//给队列结点申请空间
        list_pnew->p=pnew;
        if(NULL==tree){
            tree=pnew;//树根
            phead=list_pnew;//队列头
            ptail=list_pnew;//队列尾
            pcur=list_pnew;
        }else{
            //让元素入队
            ptail->next=list_pnew;//新结点放入链表，通过尾插法
            ptail=list_pnew;//ptail指向队列尾部
            if(pcur->p->lchild==NULL){//如何把新结点放入树
                pcur->p->lchild=pnew;//把新结点放到要插入结点的左边
            }else if(pcur->p->rchild==NULL){
                pcur->p->rchild=pnew;//把新结点放到要插入结点的右边
                pcur=pcur->next;//左右都放了结点后，pcur指向队列的下一个
            }
        }
    }
    PreOrder(tree,0);
    printf("%d\n", wpl);
    return 0;
}