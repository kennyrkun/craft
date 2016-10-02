#ifndef HEIGHT_GENERATOR_H
#define HEIGHT_GENERATOR_H


namespace Height_Generator
{
    void setUp( double amplitude,           //Higher = Higer
                double roughness    = 0.3,  //Lower  = smoother
                int ocataves        = 3,    //Higher = Smoother
                int seed            = -1 ); //Seed for the generator

    int getHeight ( double x, double z, double gridX, double gridZ );

    int getSeed   ();
}

#endif // HEIGHT_GENERATOR_H