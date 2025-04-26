#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Helper function to print the linked list
    void printList(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->val << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    // Function to find the middle node of the linked list using slow and fast pointers
    ListNode* getMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        // Create a dummy node to avoid edge cases
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        // Compare and merge nodes from both lists
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        
        // Attach remaining nodes if any
        if (left != nullptr)
            current->next = left;
        if (right != nullptr)
            current->next = right;
        
        return dummy.next;
    }

    // Main merge sort function
    ListNode* mergeSort(ListNode* head) {
        // Base case: if list is empty or has only one element
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // Find the middle of the list
        ListNode* middle = getMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;  // Split the list into two halves
        
        // Recursively sort both halves
        ListNode* left_sorted = mergeSort(head);
        ListNode* right_sorted = mergeSort(right);
        
        // Merge the sorted halves
        return merge(left_sorted, right_sorted);
    }

    // Helper function to create a list from an array
    ListNode* createList(std::initializer_list<int> values) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for (int val : values) {
            ListNode* newNode = new ListNode(val);
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        return head;
    }
};

int main() {
    Solution solution;

    // Create a linked list from an array
    ListNode* head = solution.createList({4, 2, 1, 3, 5, 6});

    std::cout << "Original list: ";
    solution.printList(head);

    // Sort the linked list using MergeSort
    ListNode* sortedList = solution.mergeSort(head);

    std::cout << "Sorted list: ";
    solution.printList(sortedList);

    return 0;
} 