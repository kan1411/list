#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string hoTen;
    string mssv;
    int namSinh;
    float gpa;
};

struct Node {
    SinhVien info;  
    Node* link;     
};

struct List {
    Node* firstNode;
};

void Init(List &list) {
    list.firstNode = NULL;
}

Node* CreateNode(SinhVien sv) {
    Node* p = new Node;
    p->info = sv;
    p->link = NULL;
    return p;
}
//Thêm vào đầu
void Insert_First(List &list, SinhVien sv) {
    Node* p = CreateNode(sv);
    p->link = list.firstNode;
    list.firstNode = p;
}
//In danh sach
void List_Display(List* list) {
    Node* p = list->firstNode;

    if (p == NULL) {
        cout << "Danh sach rong!\n";
        return;
    }

    while (p != NULL) {
        cout << "Ho ten: " << p->info.hoTen << "\n";
        cout << "MSSV: " << p->info.mssv << "\n";
        cout << "Nam sinh: " << p->info.namSinh << "\n";
        cout << "GPA: " << p->info.gpa << "\n";
        cout << "-----------------------------\n";
        p = p->link;
    }
}
//Tinh chieu dai
int List_Length(List* list) {
    int count = 0;
    Node* p = list->firstNode;

    while (p != NULL) {
        count++;
        p = p->link;
    }

    return count;
}
//Dem GPA>3.2
int Count_GPA_Higher(List* list) {
    int count = 0;
    Node* p = list->firstNode;

    while (p != NULL) {
        if (p->info.gpa > 3.2)
            count++;
        p = p->link;
    }

    return count;
}
//Sap xep tang dan
void Sort_GPA(List &list) {
    for (Node* i = list.firstNode; i != NULL; i = i->link) {
        for (Node* j = i->link; j != NULL; j = j->link) {
            if (i->info.gpa > j->info.gpa) {
                SinhVien temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}
//Chen
void Insert_Sorted(List &list, SinhVien sv) {
    Node* p = CreateNode(sv);

    if (list.firstNode == NULL || sv.gpa < list.firstNode->info.gpa) {
        p->link = list.firstNode;
        list.firstNode = p;
        return;
    }

    Node* q = list.firstNode;
    while (q->link != NULL && q->link->info.gpa < sv.gpa) {
        q = q->link;
    }

    p->link = q->link;
    q->link = p;
}

int main() {
    List list;
    Init(list);

    Insert_First(list, {"Nguyen Van A", "SV001", 2002, 3.5});
    Insert_First(list, {"Tran Thi B", "SV002", 2003, 2.8});
    Insert_First(list, {"Le Van C",   "SV003", 2001, 3.9});
    Insert_First(list, {"Pham Van D", "SV004", 2002, 3.1});

    cout << "DANH SACH BAN DAU\n";
    List_Display(&list);

    cout << "Chieu dai danh sach: " << List_Length(&list) << "\n";
    cout << "So SV GPA > 3.2: " << Count_GPA_Higher(&list) << "\n\n";

    cout << "DANH SACH SAU KHI SAP XEP GPA TANG DAN\n";
    Sort_GPA(list);
    List_Display(&list);

    // Thêm SV GPA = 2.4 vào đúng vị trí
    SinhVien svMoi = {"Sinh vien moi", "SV999", 2004, 2.4};
    Insert_Sorted(list, svMoi);

    cout << "\nDANH SACH SAU KHI THEM SV GPA 2.4\n";
    List_Display(&list);

    return 0;
}
