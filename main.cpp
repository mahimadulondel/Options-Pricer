#pragma once
#include "BlackScholesPricer.h"
#include "CallOption.h"
#include "PutOption.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "CRRPricer.h"
#include "AsianCallOption.h"
#include "AsianPutOption.h"
#include "BlackScholesMCPricer.h"
#include "AmericanCallOption.h"
#include "AmericanPutOption.h"


int main()
{
    /*
    std::cout << "***************** TD 5_6 ********************************" << std::endl;
    std::cout << std::endl;

    double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
    CallOption opt1(T, K);
    
    PutOption opt2(T, K);
    BlackScholesPricer pricer1(&opt1, S0, r, sigma);
    std::cout << "BlackScholesPricer price=" << pricer1() << ", delta=" << pricer1.delta() << std::endl;

    BlackScholesPricer pricer2(&opt2, S0, r, sigma);
    std::cout << "BlackScholesPricer price=" << pricer2() << ", delta=" << pricer2.delta() << std::endl;
    std::cout << std::endl;

    int N(150);
    double U = exp(sigma * sqrt(T / N)) - 1.0;
    double D = exp(-sigma * sqrt(T / N)) - 1.0;
    double R = exp(r * T / N) - 1.0;

    std::cout << "*********************************************************" << std::endl;
    

    
    BinaryTree<int> tree;

    tree.setDepth(6);
    tree.setNode(0, 0, 100);
    tree.setNode(1, 0, 900);
    tree.setNode(1, 1, 110);
    tree.setNode(2, 0, 81);
    tree.setNode(2, 1, 99);
    tree.setNode(2, 2, 121);
    tree.setNode(3, 0, 121);
    tree.setNode(3, 1, 103);
    tree.setNode(3, 2, 213);
    tree.setNode(3, 3, 88);
    tree.setNode(4, 0, 140);
    tree.setNode(4, 1, 67);
    tree.setNode(4, 2, 134);
    tree.setNode(4, 3, 10);
    tree.setNode(4, 4, 198);
    tree.setNode(5, 0, 140);
    tree.setNode(5, 1, 67);
    tree.setNode(5, 2, 134);
    tree.setNode(5, 3, 10);
    tree.setNode(5, 4, 198);
    tree.setNode(5, 5, 199);
    tree.display();
    

    CRRPricer pricer(&opt1, 4, 100, 0.1, -0.1, 0.02);
    pricer.compute();
    pricer.getTree().display();
    std::cout << pricer.get(0, 0) << std::endl;

    CRRPricer pricer2(&opt1, 4, 100, 0.1, -0.1, 0.02);
    std::cout << pricer2() << std::endl;
    std::cout << pricer2(true);
    */
    /*
    {

        double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
        CallOption opt1(T, K);
        PutOption opt2(T, K);

        
        std::cout << "European options 1" << std::endl << std::endl;
        
        {
            BlackScholesPricer pricer1(&opt1, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer1() << ", delta=" << pricer1.delta() << std::endl;

            BlackScholesPricer pricer2(&opt2, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer2() << ", delta=" << pricer2.delta() << std::endl;
            std::cout << std::endl;

            int N(150);
            double U = exp(sigma * sqrt(T / N)) - 1.0;
            double D = exp(-sigma * sqrt(T / N)) - 1.0;
            double R = exp(r * T / N) - 1.0;

            CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer1() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer1(true) << std::endl;
            std::cout << std::endl;

            CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer2() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer2(true) << std::endl;
        }
        std::cout << std::endl << "*********************************************************" << std::endl;
    }
    
    
    {
        std::cout << "Binary Tree" << std::endl << std::endl;
        BinaryTree<bool> t1;
        t1.setDepth(3);
        t1.setNode(1, 1, true);
        t1.display();
        t1.setDepth(5);
        t1.display();
        t1.setDepth(3);
        t1.display();


        BinaryTree<double> t2;
        t2.setDepth(2);
        t2.setNode(2, 1, 3.14);
        t2.display();
        t2.setDepth(4);
        t2.display();
        t2.setDepth(3);
        t2.display();

        BinaryTree<int> t3;
        t3.setDepth(4);
        t3.setNode(3, 0, 8);
        t3.display();
        t3.setDepth(2);
        t3.display();
        t3.setDepth(4);
        t3.display();

        std::cout << std::endl << "*********************************************************" << std::endl;
    }
    
    
    */

    /*
    double S0(100.), K(100.), T(1.), r(0.05), sigma(0.2);
    CallOption opt1(T, K);
    PutOption opt2(T, K);
    DigitalCallOption opt3(T, K);
    DigitalPutOption opt4(T, K);


    std::cout << "Vanilla options " << std::endl << std::endl;


    BlackScholesPricer pricerv1(&opt1, S0, r, sigma);
    std::cout << "BlackScholesPricer price=" << pricerv1() << ", delta=" << pricerv1.delta() << std::endl;

    BlackScholesPricer pricerv2(&opt2, S0, r, sigma);
    std::cout << "BlackScholesPricer price=" << pricerv2() << ", delta=" << pricerv2.delta() << std::endl;
    std::cout << std::endl;

    std::cout << "Digital options " << std::endl << std::endl;


    BlackScholesPricer pricerd1(&opt3, S0, r, sigma);
    std::cout << "BlackScholesPricer price=" << pricerd1() << ", delta=" << pricerd1.delta() << std::endl;

    BlackScholesPricer pricerd2(&opt4, S0, r, sigma);
    std::cout << "BlackScholesPricer price=" << pricerd2() << ", delta=" << pricerd2.delta() << std::endl;
    std::cout << std::endl;
    
    */

    // Test BlackScholesMCPricer & CI
    /*
    double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
    std::vector<double> fixing_dates;
    for (int i = 1; i <= 5; i++) {
        fixing_dates.push_back(0.1 * i);
    }

    AsianCallOption ascall(fixing_dates, K);
    CallOption opt1(T, K);

    
    BlackScholesPricer pricer1(&opt1, S0, r, sigma);
    std::cout << "BlackScholesPricer price=" << pricer1() << ", delta=" << pricer1.delta() << std::endl;

    BlackScholesMCPricer pricer2(&opt1, S0, r, sigma);
    pricer2();
    pricer2.generate(1000000);
    std::cout << "BlackScholesMCPricer price=" << pricer2() << std::endl;
    std::cout << "Confidence interval = [" << pricer2.confidenceInterval()[0] << "; " << pricer2.confidenceInterval()[1] << "]" << std::endl;

    
    
    PutOption opt2(T, K);

    BlackScholesPricer pricer3(&opt2, S0, r, sigma);
    std::cout << "BlackScholesPricer price=" << pricer3() << ", delta=" << pricer3.delta() << std::endl;

    BlackScholesMCPricer pricer4(&opt2, S0, r, sigma);
    pricer4();
    pricer4.generate(1000000);
    std::cout << "BlackScholesMCPricer price=" << pricer4() << std::endl;
    std::cout << "Confidence interval = [" << pricer4.confidenceInterval()[0] << "; " << pricer4.confidenceInterval()[1] << "]" << std::endl;
    */




    /*


    // Test TD7 Prof

    double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
    std::vector<Option*> opt_ptrs;
    opt_ptrs.push_back(new CallOption(T, K));
    opt_ptrs.push_back(new PutOption(T, K));
    opt_ptrs.push_back(new DigitalCallOption(T, K));
    opt_ptrs.push_back(new DigitalPutOption(T, K));

    std::vector<double> fixing_dates;
    for (int i = 1; i <= 5; i++) {
        fixing_dates.push_back(0.1 * i);
    }
    opt_ptrs.push_back(new AsianCallOption(fixing_dates, K));
    opt_ptrs.push_back(new AsianPutOption(fixing_dates, K));

    std::vector<double> ci;
    BlackScholesMCPricer* pricer;

    for (auto& opt_ptr : opt_ptrs) {
        pricer = new BlackScholesMCPricer(opt_ptr, S0, r, sigma);
        do {
            pricer->generate(10);
            ci = pricer->confidenceInterval();
        } while (ci[1] - ci[0] > 1e-2);
        std::cout << "nb samples: " << pricer->getNbPaths() << std::endl;
        std::cout << "price: " << (*pricer)() << std::endl << std::endl;
        delete pricer;
        delete opt_ptr;
    }
    */

    double S0(80.), K(100.), T(0.5), r(0.02), sigma(0.2);
    std::vector<Option*> opt_ptrs;

    opt_ptrs.push_back(new CallOption(T, K));
    opt_ptrs.push_back(new PutOption(T, K));
    opt_ptrs.push_back(new DigitalCallOption(T, K));
    opt_ptrs.push_back(new DigitalPutOption(T, K));
    opt_ptrs.push_back(new AmericanCallOption(T, K));
    opt_ptrs.push_back(new AmericanPutOption(T, K));

    CRRPricer* pricer;

    for (auto& opt_ptr : opt_ptrs) {
        pricer = new CRRPricer(opt_ptr, 150, S0, r, sigma);

        pricer->compute();

        std::cout << "price: " << (*pricer)() << std::endl << std::endl;
        delete pricer;
        delete opt_ptr;

    }
}

