package programmers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		// println보다 버퍼가 훨씬 빠르다.
		/*
		 * 입출력 스트림(프린트문)은 운영체제 API를 호출해가면서 작동하는데 이는 하드디스크, 네트워크 장치를 호출하면서 작동하므로 다수의 출력문
		 * 사용 시 비효율적일 수 있다.
		 * 
		 * 만약 스트림이 버퍼를 사용하여 자료를 모아두었다가 한번에 보낸다면
		 */
		// BufferedReader : 문자 입력 버퍼 스트림
		// BufferedWriter : 문자 출력 버퍼 스트림

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 입
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); // 출
		// 버퍼 선언
		StringTokenizer st; // 스트링 자르는 클래스
		// String s = br.readLine(); // readline은 반드시 string로 선언, 메인에 예외처리 추가
		
		int n = Integer.parseInt(br.readLine()); //여기서 숫자 5 입력
		for (int i = 0; i < n; i++) {
			
			st = new StringTokenizer(br.readLine());// 1 1 입력 하면
			bw.write((Integer.parseInt(st.nextToken())+Integer.parseInt(st.nextToken()))+"\n");
			//출력 하고 줄바꿈, nextToken() 함수를 쓰면 공백 단위로 구분이 가능 이외에 스플릿으로 구분 가능
		}
			bw.close();// close나 flush로 반드시 버퍼라이터를 닫아주기 플러시는 남은데이터(모아뒀던 원기옥) 모두 출력해내는것
	}
}