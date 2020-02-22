#include<stdio.h>

int main(){
	int index = 0;
	int max_len = 0, max_left = 0, max_start = 0; 
	int v_prev = 1000000, v_start = 1, v_len = 0, v_left = 0, v_right = 0;
	int m_prev = -1, m_start = 1, m_len = 0, m_left = 0, m_right = 0;
	int x;
	while( scanf("%d", &x) == 1 ){
		index++;
		if( x > m_prev && m_right == 0 )		//mountain_left
			m_left++;
		else if( x < m_prev && m_left > 1 )		//mountain_right
			m_right++;
		else{									//end of a mountain
			m_len = (m_right == 0)? 0: m_right + m_left;
			if( m_len > max_len || ((m_len == max_len) && (m_left > max_left)) )
				max_len = m_len, max_left = m_left, max_start = m_start;
			m_left = (m_prev < x)? 2:1, m_right = 0, m_start = (m_prev < x)? index-1: index;
		}
		m_prev = x;
		
		if( x < v_prev && v_right == 0 )		//valley_left
			v_left++;
		else if( x > v_prev && v_left > 1 )		//valley_right
			v_right++;
		else{									//end of a valley
			v_len = (v_right == 0)? 0: v_right + v_left;
			if( v_len > max_len || ((v_len == max_len) && (v_left > max_left)) )
				max_len = v_len, max_left = v_left, max_start = v_start;
			v_left = (v_prev > x)? 2:1, v_right = 0, v_start = (v_prev > x)? index-1: index;
		}
		v_prev = x; 
	}

	m_len = (m_right == 0)? 0: m_right + m_left;
	if( m_len > max_len || ((m_len == max_len) && (m_left > max_left)) )
		max_len = m_len, max_left = m_left, max_start = m_start;

	v_len = (v_right == 0)? 0: v_right + v_left;
	if( v_len > max_len || ((v_len == max_len) && (v_left > max_left)) )
		max_len = v_len, max_left = v_left, max_start = v_start;

	if( max_len == 0 )
		printf("0\n");
	else
		printf("%d %d\n", max_len, max_start);
	return 0;
}