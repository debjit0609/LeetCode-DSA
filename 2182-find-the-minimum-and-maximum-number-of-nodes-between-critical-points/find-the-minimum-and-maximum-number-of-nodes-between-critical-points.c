int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;

    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return result;
    }

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    
    int index = 1;
    int firstCritical = -1;
    int lastCritical = -1;
    int minDistance = -1;

    while (curr->next != NULL) {
        int isMaxima = (curr->val > prev->val) && (curr->val > curr->next->val);
        int isMinima = (curr->val < prev->val) && (curr->val < curr->next->val);

        if (isMaxima || isMinima) {
            if (firstCritical == -1) {
                firstCritical = index;
            } else {
                int currentDistance = index - lastCritical;
                if (minDistance == -1 || currentDistance < minDistance) {
                    minDistance = currentDistance;
                }
            }
            lastCritical = index;
        }

        prev = curr;
        curr = curr->next;
        index++;
    }

    if (firstCritical != -1 && firstCritical != lastCritical) {
        result[0] = minDistance;
        result[1] = lastCritical - firstCritical;
    }

    return result;
}