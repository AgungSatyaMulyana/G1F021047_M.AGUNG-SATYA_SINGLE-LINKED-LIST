#include <iostream>
using namespace std;

struct Baju{
  string merek, warna, ukuran;

  Baju *next;
};

Baju *head, *tail, *newNode, *cur, *del;

void createCircularSingleLinkedList(string dataBaru[3]){

  head = new Baju();
  head->merek = dataBaru[0];
  head->warna = dataBaru[1];
  head->ukuran = dataBaru[2];
  tail = head;
  tail->next = head;

}

void addFirst( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    newNode = new Baju();
    newNode->merek = data[0];
    newNode->warna = data[1];
    newNode->ukuran = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

void addLast( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    newNode = new Baju();
    newNode->merek = data[0];
    newNode->warna = data[1];
    newNode->ukuran = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string data[3], int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi satu bukan posisi tengah!!!" << endl;
    }else{
      newNode = new Baju();
      newNode->merek = data[0];
      newNode->warna = data[1];
      newNode->ukuran = data[2];

      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

void removeLast()
{
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}

void removeMiddle(int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    // tranversing
    int nomor = 1;
    cur = head;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}

void printCircular()
{
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    cout << " List Baju " << endl;
    cout << "________________________________________________________________" << endl; 
    cout << "| MEREK\t\t| WARNA\t\t\t| UKURAN\t\t|" << endl;
    cout << "________________________________________________________________" << endl; 
    cur = head;
    while (cur->next != head)
    {
      // print
      cout << "| " << cur->merek << "\t| " << cur->warna << "\t| " << cur->ukuran << "\t\t|" << endl;
      cur = cur->next;
    }
    cout << "| " << cur->merek << "\t| " << cur->warna << "\t| " << cur->ukuran << "\t\t|" << endl;
    cout << "_________________________________________________________________" << endl;
  }
}


int main(){
  string dataBaru[3] = {"ADIDAS", "HITAM", "M"};
  createCircularSingleLinkedList(dataBaru);

  printCircular();

  string data[3] = {"H&M", "MERAH", "XL"};
  addFirst(data);

  printCircular();

  string data2[3] = {"GUCCI", "BIRU", "L"};
  addLast(data2);

  printCircular();

  string data3[3] = {"CHANEL", "PUTIH", "XXL"};
  addMiddle(data3, 5);

  printCircular();

  removeMiddle(6);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}
