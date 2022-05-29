/*
    Leetcode 23: Merge k Sorted Lists (https://leetcode.com/problems/merge-k-sorted-lists/)

    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
    Merge all the linked-lists into one sorted linked-list and return it.

    @author Yuho Jeong
*/

#include <iostream>
#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    static ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto* answer = new ListNode;
        ListNode *cur_answer_node = answer;
        bool done = false;

        // Only consider the smallest element of each list (= search_list)
        std::vector<ListNode*> search_list;
        for (ListNode *min_node: lists) {
            // Exception for "[[]]" case
            if (min_node != nullptr) {
                search_list.push_back(min_node);
            }
        }

        // Check the length of search_list
        // Exception for "[]" case
        if (search_list.empty()) {
            answer = nullptr;
            done = true;
        }

        while (!done) {
            int min_val = 1e+5;
            int min_index = -1;

            // Find the minimum value in search list.
            for (int i = 0; i < search_list.size(); i ++){
                ListNode *cur_search_node = search_list[i];

                if (cur_search_node != nullptr) {
                    if (min_val > cur_search_node->val) {
                        min_val = cur_search_node->val;
                        min_index = i;
                    }
                }
            }

            // There is no assigned minimum value. All search nodes are nullptr.
            if (min_val == 1e+5 and min_index == -1) {
                done = true;
            }
            else {
                cur_answer_node->val = min_val;
                search_list[min_index] = search_list[min_index]->next;

                // Check whether search_list has only nullptr
                bool all_null = true;
                for (auto & node : search_list) {
                    if (node != nullptr) {
                        all_null = false;
                        break;
                    }
                }

                if (!all_null) {
                    cur_answer_node->next = new ListNode;
                    cur_answer_node = cur_answer_node->next;
                }
            }
        }
        return answer;
    }
};

