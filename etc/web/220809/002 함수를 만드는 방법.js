// 함수를 두 개 만들어라. 함수명은 a 다른 함수명은 b
// console.log("hello world") 하는 함수


// 1번 방법 : 함수선언문 이용 - > 함수 호이스팅 발생
function a(){
    console.log("hello world")
}

// 2번 방법 : 무명 함수 이용
const b = function(){
    console.log("hello world")
}

// 함수를 만드는 3번째 방법! : 회실표 함수
// function : =>
const c = () => {
    console.log("hello world")
}



//================== 문자열 받아서 출력하는 함수 ================

// 1번 방법 : 함수선언문 이용 - > 함수 호이스팅 발생
function a(str){
    console.log(str)
}

a("ABC")

// 2번 방법 : 무명 함수 이용
const d = function(str){
    console.log(str)
}

b("ABC")

// 함수를 만드는 3번째 방법! : 회실표 함수
// function : =>
// 화살표 함수에서만 가능한게 매개변수가 1개이면 () 삭제 가능
```const e = (str) => {
    console.log(str)
}

c("ABC")```

const e = str => {
    console.log(str)
    // 함수 몸체 안에 표현식이 1개밖에 없으면 return을 생략할 수 있다
}

//const c = str => { (return 생략 가능) str }
//const c = str => str   : 중괄호도 생략


c("ABC")