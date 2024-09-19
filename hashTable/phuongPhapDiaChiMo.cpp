#include <iostream>
using namespace std;

const int TABLE_SIZE = 10; // Kích thước của bảng băm

// Node chứa khóa và trạng thái
struct HashNode
{
    int key;
    bool isOccupied;

    HashNode() : key(0), isOccupied(false) {}
};

class HashTable
{
private:
    HashNode *table;

public:
    HashTable()
    {
        table = new HashNode[TABLE_SIZE];
    }

    // Hàm băm
    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

    // Thêm một khóa vào bảng
    bool insert(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 1;

        // Tìm vị trí trống bằng phương pháp địa chỉ mở
        while (table[index].isOccupied)
        {
            index = (originalIndex + i) % TABLE_SIZE;
            if (index == originalIndex)
            {
                cout << "Bảng băm đã đầy!" << endl;
                return false;
            }
            i++;
        }

        table[index].key = key;
        table[index].isOccupied = true;
        return true;
    }

    // Tìm kiếm một khóa trong bảng
    bool search(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 1;

        while (table[index].isOccupied)
        {
            if (table[index].key == key)
            {
                return true;
            }
            index = (originalIndex + i) % TABLE_SIZE;
            if (index == originalIndex)
            {
                return false; // Đã duyệt hết bảng mà không tìm thấy
            }
            i++;
        }

        return false;
    }

    // Xóa một khóa khỏi bảng
    bool remove(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 1;

        while (table[index].isOccupied)
        {
            if (table[index].key == key)
            {
                table[index].isOccupied = false;
                return true;
            }
            index = (originalIndex + i) % TABLE_SIZE;
            if (index == originalIndex)
            {
                return false; // Không tìm thấy khóa cần xóa
            }
            i++;
        }

        return false;
    }

    // Hiển thị bảng băm
    void display()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (table[i].isOccupied)
            {
                cout << "Index " << i << ": " << table[i].key << endl;
            }
            else
            {
                cout << "Index " << i << ": empty" << endl;
            }
        }
    }

    ~HashTable()
    {
        delete[] table;
    }
};

int main()
{
    HashTable hashTable;

    // Thêm các khóa vào bảng băm
    hashTable.insert(23);
    hashTable.insert(34);
    hashTable.insert(56);
    hashTable.insert(78);
    hashTable.insert(12);

    // Hiển thị bảng băm
    hashTable.display();

    // Tìm kiếm khóa
    cout << (hashTable.search(34) ? "Tim thay 34" : "Khong tim thay 34") << endl;

    // Xóa khóa
    hashTable.remove(34);
    hashTable.display();

    return 0;
}
