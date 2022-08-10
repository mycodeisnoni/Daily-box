const arr=[1,2,3]
// arr 하나 하나를 element
// javascript 는 배열이 없어요!
// 유사배열객체
```const obj = {
    0 : 1,
    1 : 2,
    2 : 3,
    length : 3
}```


//element를 모두 출력하라!

//console.log(arr[0]) 
//console.log(arr[1])
// element 가 무한대가 되면? 너무 복잡




for(let i=0;i<arr.length;i++){
    console.log(arr[i])
}
// 순회 . element가 무한대가 되어도 o.k.
// arr.length 객체(ex.  obj.name )

const obj = {
    name : "heo",  // 프로퍼티
    //프로퍼티 키 : 프로퍼티 밸류

    // 메서드 : 객체 안의 함수
    test : function(){
        console.log("hi")
    }
}



// obj.0 === obj["0"]