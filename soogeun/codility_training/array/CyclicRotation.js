// Codility Training - Array 1 (Cyclic Rotation)
// 문제 링크: https://app.codility.com/programmers/lessons/2-arrays/
// 풀이 링크: https://app.codility.com/demo/results/training3E7JDW-UNV/

function solution(A, K) {
    const result = [...A];

    for (let i = 0; i < result.length; i++) {
        const destIdx = (i + K) % A.length;
        result[destIdx] = A[i];
    }

    return result;
}

/**
 * 인사이트
 * array 복사는 spread operator 이용하기 !
 */
