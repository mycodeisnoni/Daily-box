function getData(){
    //서버와 통신하기 위한 과정
    // 1. 생성
    // 2. 열기
    // 3. 보내기
    
    
    //1. 생성
    const httprequest = new XMLHttpRequest()
    
    
    httprequest.onreadystatechange = function(){
        console.log(httprequest.readyState)
        if(httprequest.readyState === httprequest.DONE){
            console.log(httprequest.response)
        }else{
            console.log(httprequest.text)
        }
    }
    
    //2. 열기 (open) (매개변수 HTTP METHOD, URL)
    httprequest.open("GET","https://jsonplaceholder.typicode.com/todos/")
    httprequest.send()
    
    //console.log(httprequest)
    // 3.보내기 (send)
    
    
    
    
    // readyState 단계
    // 0 request가 초기화되지 않은 상태
    // 1 서버와 연결이 성사된 loading 단계
    // 2 서버가 request를 받은, loaded 상태
    // 3 request를 처리하는 중인 interactive 단계
    // 4 완료단계 (request에 대한 요청이 끝났고 응답을 준비)
}

getData()