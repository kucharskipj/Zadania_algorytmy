int my_function(int x) {
    x=x+1;
return 0;
}

int main(int argc, char **argv)
{
    int x,y;
	x=1;
	y=1;
    x=y;
    my_function(x);
    return 0;
}
