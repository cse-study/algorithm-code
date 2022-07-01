// Codility Training - Counting Element 1 (PermCheck)
// 문제 링크: https://app.codility.com/programmers/lessons/4-counting_elements/

/**
 * 인사이트 1
 * 배열 A의 원소의 value들의 범위를 알 때, A 배열의 element들의 value의 개수를 알고 싶은 상황이라면
 * 범위 크기만큼의 0으로 초기화 된 count array를 생성하고, A 배열을 순회하면서 'C[ A[i] + 상수 ] += 1'
 * 연산을 수행하여 count 배열을 만들어서 사용할 수 있다. O(n + m) (n: A의 length, m: value 범위)
 */
function solution(A) {

    const count = new Array(A.length);
    for (let i = 0; i < A.length; i++) {
        count[i] = 0;
    }

    for (let i = 0; i < A.length; i++) {
        count[ A[i] - 1 ] += 1;
    }

    for (let i = 0; i < A.length; i++) {
        if (count[i] !== 1){
            return 0;
        }
    }

    return 1;
}


/**
 * count 하는 for문에서 count 배열의 length 보다 큰 index의 접근을 할 경우
 * 0를 리턴할 수 있도록 하여, Overflow 방지 및 성능 향상을 개선했습니다.
 * javascript 문법 상 overflow가 발생하지는 않음.
 */
function solution(A) {

    const len = A.length;
    const count = new Array(len).fill(0);

    for (let i = 0; i < len; i++) {
        if (A[i] > len) {
            return 0;
        }
        count[ A[i] - 1 ] += 1;
    }

    for (let i = 0; i < len; i++) {
        if (count[i] !== 1){
            return 0;
        }
    }

    return 1;
}