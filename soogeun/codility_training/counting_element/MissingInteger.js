// Codility Training - Counting Element 2 (Missing Integer)
// 문제 링크: https://app.codility.com/programmers/lessons/4-counting_elements/

function solution(A) {
    let minInt = 1;
    const MAX = 100000;     // 100,000: Max length of A

    let count = new Array(MAX + 1).fill(0);    

    for (let i = 0; i < A.length; i++) {
        if (A[i] <= 0 || A[i] > MAX) {
            continue;
        }
        count[ A[i] - 1 ] += 1;
    }

    for (let i = 0; i < MAX + 1; i++) {
        if (count[i] === 0) {
            minInt = i + 1;
            break;
        }
    }

    return minInt;
}