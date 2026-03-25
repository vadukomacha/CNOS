#include &lt;stdio.h&gt; 
#include &lt;stdlib.h&gt; 
int main() 
{
int n, size, i; 
int free_blocks[100];
for(i=0;i&lt;100;i++) free_blocks[i]=0;
printf(&quot;Enter number of files: &quot;);
scanf(&quot;%d&quot;,&amp;n);
for(i=0;i&lt;n;i++)
{
printf(&quot;Enter size of file %d: &quot;, i+1);
scanf(&quot;%d&quot;,&amp;size);
int index_block=-1;
int j;
for(j=0;j&lt;100;j++)
{
if(free_blocks[j]==0) { index_block=j; free_blocks[j]=1; break; }
}
if(index_block==-1) { printf(&quot;No free block for index\n&quot;); continue; }
int *blocks = (int*)malloc(size*sizeof(int)); 
int count=0;
for(j=0;j&lt;100 &amp;&amp; count&lt;size;j++)
{
if(free_blocks[j]==0) { blocks[count]=j; free_blocks[j]=1; count++; }
}
if(count&lt;size) { printf(&quot;Not enough free blocks\n&quot;); free(blocks); continue; }
printf(&quot;File %d allocated. Index block: %d, Data blocks: &quot;, i+1, index_block);
for(j=0;j&lt;size;j++) printf(&quot;%d &quot;, blocks[j]);
printf(&quot;\n&quot;);
free(blocks); 
}
return 0;
}
