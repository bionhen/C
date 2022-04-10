#include <iostream>

using namespace std;

struct Element {
    int key;
    Element* next;
};

void data_in(Element*& List) {
    Element* tmp = new Element;
    int a = 0;
    cin >> a;
    tmp->key = a;
    tmp->next = new Element;
    List = tmp;
    tmp = tmp->next;
    while (tmp->next != nullptr) {
        cin >> a;
        if (a == 0) {
            tmp->next = nullptr;
            return;
        }
        tmp->key = a;
        tmp->next = new Element;
        tmp = tmp->next;
    }
    delete tmp;
    return;
}

void add(Element*& List, int x) {
    Element* N = new Element;
    N->key = x;
    N->next = List;
    List = N;
    return;
}

void delete_list(Element*& List) {
    while (List != nullptr) {
        Element* tmp = List;
        List = tmp->next;
        delete tmp;
    }
    List = nullptr;
    return;
}

void add_sort(Element*& List, int a) {
    Element* tmp = List;
    tmp = List;
    while (tmp->next != nullptr) {
        if (List->key > a) {
            add(List, a);
            return;
        }
        if (tmp->key <= a && tmp->next->key > a) {
            Element* N = new Element;
            N->key = a;
            N->next = tmp->next;
            tmp->next = N;
            return;
        }
        if (tmp->next->next == nullptr) {
            Element* N = new Element;
            N->key = a;
            N->next = tmp->next;
            tmp->next = N;
            return;
        }
        tmp = tmp->next;
    }
    return;
}

void delete_key(Element*& List, int k) {
    while (List->key == k) {
        Element* tmp = List;
        List = List->next;
        delete tmp;
    }
    Element* tmp = List;
    tmp = List;
    while (tmp->next != nullptr) {
        if (tmp->next->key == k) {
            Element* tmp_1 = tmp->next;
            tmp->next = tmp->next->next;
            delete tmp_1;
        }
        else {
            tmp = tmp->next;
        }
    }
    return;
}

void data_out(Element*& List) {
    cout << '\n';
    Element* tmp = List;
    tmp = List;
    while (tmp->next != nullptr) {
        cout << tmp->key << " ";
        tmp = tmp->next;
    }
    return;
}

void add_to_begin(Element*& List) {
    int n = 0;
    data_in(List);
    cin >> n;
    add(List, n);
    data_out(List);
    delete_list(List);
}

void add_to_sort(Element*& List) {
    int n = 0;
    data_in(List);
    cin >> n;
    add_sort(List, n);
    data_out(List);
    delete_list(List);
}

void delete_of_key(Element*& List) {
    int n = 0;
    data_in(List);
    cin >> n;
    delete_key(List, n);
    data_out(List);
    delete_list(List);
}

int main() {
    Element* List = nullptr;
    add_to_begin(List);
    add_to_sort(List);
    delete_of_key(List);
    return 0;
}