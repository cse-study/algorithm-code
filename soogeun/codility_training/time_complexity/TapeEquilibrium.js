// Codility Training - Time Complexity (TapeEquilibrium)
// Problem  Link  : https://app.codility.com/programmers/lessons/3-time_complexity/

/**
 * Solution 1: 46%
 * Binary Search 방법을 사용하고자 했으나, 음수를 고려하지 않았기 때문에 46% pass되었다.
 */
function solution(A) {
    let diff;
    let leftSum = 0;
    let rightSum = 0;

    let start = 0;
    let mid = Math.trunc(A.length / 2);
    let end = A.length;

    while (start < mid) {
        leftSum += sumOfArray(A.slice(start, mid));
        rightSum += sumOfArray(A.slice(mid, end));
        
        const nextDiff = leftSum - rightSum;
        if ( !diff || Math.abs(diff) > Math.abs(nextDiff) ) {
            diff = nextDiff;
        }

        // diff가 0이면 최소값이기 때문에 바로 출력한다.
        if (diff === 0) {
            return 0;
        }

        // left > right => 왼쪽 선택
        else if (diff > 0) {
            end = mid;
            mid = Math.trunc(mid / 2);
            leftSum = 0;
        }

        // left < right => 오른쪽 선택
        else {
            start = mid;
            mid = Math.trunc((start + end) / 2);
            rightSum = 0;
        }
    }

    return diff < 0 ? -diff : diff;
}

function sumOfArray(array) {
    let sum = 0;
    for (let i = 0; i < array.length; i++) {
        sum += array[i];
    }
    return sum;
}


/**
 * Solution 2: 69% 
 * Diff가 최소인 점을 찾아야 하는데, 처음 만나는 변곡점에서 loop를 종료했기 때문에
 * 극점이 2개 이상 존재하는 case에서는 fail되었다.
 */
function solution(A) {

    let leftSum = A[0];
    let rightSum = 0;

    for (let i = 1; i < A.length; i++) {
        rightSum += A[i];
    }

    let diff = Math.abs(leftSum - rightSum);

    for (let i = 1; i < A.length - 1; i++) {
        leftSum += A[i];
        rightSum -= A[i];        
        let nextDiff = Math.abs(leftSum - rightSum);
        if (diff < nextDiff)
            break;
        diff = nextDiff;
    }

    return diff;
}

/**
 * Solution 3: 100% 
 * A 배열의 길이 (n) 만큼 모두 탐색하여 diff 값을 구해 diff 배열에 저장한 후,
 * diff 배열을 오름차순 정렬한 후, 첫 번째 원소를 출력
 */
function solution(A) {
    let leftSum = A[0];
    let rightSum = 0;
    for (let i = 1; i < A.length; i++) {
        rightSum += A[i];
    }

    let diffArr = [];
    let diff = Math.abs(leftSum - rightSum);
    if (diff === 0)
        return 0;
    diffArr.push(diff);

    for (let i = 1; i < A.length - 1; i++) {
        leftSum += A[i];
        rightSum -= A[i];
        diff = Math.abs(leftSum - rightSum);
        if (diff === 0) {
            return 0;
        }
        diffArr.push(diff);
    }

    return diffArr.sort((a, b) => a - b)[0];
}

/**
 * Solution 4: 100% 
 * Solution 3과 풀이 방법은 같으나, diff 배열을 만들고 정렬하는 대신,
 * minDiff 변수를 이용해 더 작은 diff가 나온 경우 update 하는 방법으로
 * 배열의 삽입, 정렬 연산 과정을 줄임.
 */
function solution(A) {
    let leftSum = A[0];
    let rightSum = 0;
    for (let i = 1; i < A.length; i++) {
        rightSum += A[i];
    }

    let minDiff = Math.abs(leftSum - rightSum);
    if (minDiff === 0)
        return 0;

    for (let i = 1; i < A.length - 1; i++) {
        leftSum += A[i];
        rightSum -= A[i];
        let diff = Math.abs(leftSum - rightSum);
        if (diff === 0) {
            return 0;
        }
        if (minDiff > diff) {
            minDiff = diff;
        }        
    }

    return minDiff;
}

/**
 * 인사이트
 * Binary Search 하면서 각각의 search 과정에서 O(n) 연산을 하는 것보다 ( O(log(n)) * O(n) = O(nlog(n)) )
 * N 순회 과정에서 O(1) 연산을 하는 것이 더 효율적이다. ( O(n) * O(1) = O(n) )
 * 
 * 또한, 시간 효율성을 높이는 것보다 문제를 더 잘 이해하고, 직관적인 알고리즘으로 우선 구현하는 것이 더 중요하다.
 * 
 * 최소값, 최대값을 구할 때는 모든 값을 배열에 저장해 정렬하여 구하는 것보다
 * 변수를 할당해, 최소값, 최대값이 나올때 update하는 것이 훨씬 효율적이다.
 */
