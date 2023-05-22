const arr = [1,2,3]
const arr2 = [4,5]

// arr에 arr2를 넣기로 하자.

//for( const num of arr2 ) arr.push(num);
// arr2.forEach( e => arr.push(e));
arr.push(arr2)  // 배열 안에 배열을 넣을 수 있다.
// arr =[1,2,3, [4,5]]

const arr3 = [0, ...arr, ...arr2] 
// 배열에 원소값만 넣고 싶을 때 spread문법 활용