// [Modified] Source - https://stackoverflow.com/questions/5685765/computing-fft-and-ifft-with-fftw-library-c

#include <stdio.h>
#include <math.h>
#include <fftw3/fftw3.h>

#define M_PI 3.14159265358979323846
#define N 16   /* or whatever size you want */

int main(int argc, char* argv[])
{
    fftwf_complex in[N], out[N], in2[N]; /* float[2] */
    fftwf_plan p, q;
    int i;

    /* prepare a cosine wave */
    for (i = 0; i < N; i++) {
        in[i][0] = cosf(3.0f * 2.0f * (float)M_PI * i / (float)N);
        in[i][1] = 0.0f;
    }

    /* forward Fourier transform, save the result in 'out' */
    p = fftwf_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftwf_execute(p);
    for (i = 0; i < N; i++)
        printf("freq: %3d %+9.5f %+9.5f I\n",
               i, out[i][0], out[i][1]);
    fftwf_destroy_plan(p);

    /* backward Fourier transform, save the result in 'in2' */
    printf("\nInverse transform:\n");
    q = fftwf_plan_dft_1d(N, out, in2, FFTW_BACKWARD, FFTW_ESTIMATE);
    fftwf_execute(q);

    /* normalize */
    {
        float norm = 1.0f / (float)N;
        for (i = 0; i < N; i++) {
            in2[i][0] *= norm;
            in2[i][1] *= norm;
        }
    }

    for (i = 0; i < N; i++)
        printf("recover: %3d %+9.5f %+9.5f I vs. %+9.5f %+9.5f I\n",
               i, in[i][0], in[i][1], in2[i][0], in2[i][1]);

    fftwf_destroy_plan(q);
    fftwf_cleanup();
    return 0;
}