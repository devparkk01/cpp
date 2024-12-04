#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class BuddyBitmap {
private:
    vector<int> bitmap; // Represents the complete binary tree as a bitmap
    int n;              // Number of leaf nodes

    // Propagate changes upwards to maintain parent-child relationships
    void propagate_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            int left_child = 2 * parent + 1;
            int right_child = 2 * parent + 2;

            // Update parent based on children's values
            bitmap[parent] = bitmap[left_child] & bitmap[right_child];
            index = parent;
        }
    }

    // Update a single bit in the bitmap
    void update_bit(int index, int value) {
        bitmap[index] = value;
        propagate_up(index);
    }

    // Convert leaf node index to bitmap index
    int leaf_index(int offset) {
        return (bitmap.size() / 2) + offset;
    }

public:
    BuddyBitmap(int size) : n(size) {
        int height = ceil(log2(size));
        int total_nodes = (1 << (height + 1)) - 1; // Total nodes in complete binary tree
        bitmap.resize(total_nodes, 0); // Initialize all nodes to 0
    }

    // Set bits in the range [offset, offset + length - 1]
    void set_bit(int offset, int length) {
        for (int i = 0; i < length; ++i) {
            update_bit(leaf_index(offset + i), 1);
        }
    }

    // Clear bits in the range [offset, offset + length - 1]
    void clear_bit(int offset, int length) {
        for (int i = 0; i < length; ++i) {
            update_bit(leaf_index(offset + i), 0);
        }
    }


    // Debug function to print the bitmap
    void print_bitmap() {
        for (int val : bitmap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    int n = 8; // Number of leaf nodes
    BuddyBitmap buddy(n);

    // Set bits from 2 to 4
    buddy.set_bit(2, 3);
    buddy.print_bitmap();

    // Clear bits from 3 to 4
    buddy.clear_bit(3, 2);
    buddy.print_bitmap();

    return 0;
}
