#include <stdio.h>
#include <string.h>

int main(){
	char alpha[27];
	char string[100001];
	scanf("%s", string);
	int length = strlen(string);

	for( int i = 0; i < 26; i++ )
		alpha[i] = 'A' + i;

	int n;
	scanf("%d", &n);
	char u[2], v[2];
	for( int i = 0; i < n; i++ ){
		scanf("%s%s", u, v);
		for( int j = 0; j < 26; j++ )
			if( alpha[j] == v[0] )
				alpha[j] = u[0];
	}
	for( int i = 0; i < length; i++ )
		printf("%c", alpha[(string[i]-'A')]);
	printf("\n");
	return 0;
}