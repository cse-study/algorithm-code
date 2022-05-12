// Codility Training - Time Complexity 1 (FrogJmp)
// 문제 링크: https://app.codility.com/programmers/lessons/3-time_complexity/
// Solution Link 1: https://app.codility.com/demo/results/trainingEATSY4-GHH/ -> 88%  pass
// Solution Link 2: https://app.codility.com/demo/results/training6ZCMQU-W5F/ -> 100% pass

function solution(X, Y, D) {
    const distance = Y - X;
    const minJumps = distance % D === 0 
        ? Math.trunc(distance / D)          // parseInt(distance / D)
        : Math.trunc(distance / D) + 1;     // parseInt(distance / D) + 1

    return minJumps;
}

/**
 * 인사이트
 * JS에서 정수의 나눗셈 몫을 구하는 방법은 `Math.trunc(A / B)`.
 * 일반적으로 사용하는 `parseInt()`는 `string`을 `number`로 변환해주는 내장함수로, 
 * 숫자를 만나서 숫자가 아닌 문자를 만났을 때까지의 값을 반환해주는 함수임. 
 * 따라서 `123.45`의 경우, `.`을 문자로 인식하기 때문에 `123` 까지를 반환하는 것. 
 * 하지만, `1e-7`과 같은 실수 값도 e를 문자로 인식하기 때문에 예상하지 못한 값이 나올 수 있다. 
 * 따라서 `parseInt`는 문자열을 숫자로 변환할 때만 사용하도록 하자 !  
 */
