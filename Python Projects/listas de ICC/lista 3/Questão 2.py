def log(float):
    n=0
    k=(float-1)/(float+1)
    ln=0
    while (n<100):
        ln=ln+(1/(2*n+1))*k**(2*n+1)
        n=n+1
    ln=2*ln
    return ln