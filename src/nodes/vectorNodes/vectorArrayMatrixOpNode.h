/**
    Copyright (c) 2017 Ryan Porter
    You may use, distribute, or modify this code under the terms of the MIT license.
*/

#pragma once

#include <maya/MDataBlock.h>
#include <maya/MPlug.h>
#include <maya/MPxNode.h>
#include <maya/MString.h>
#include <maya/MTypeId.h>

class VectorArrayMatrixOpNode : public MPxNode
{
public:
    virtual MStatus         compute(const MPlug& plug, MDataBlock& data);
    static  void*           creator();
    static  MStatus         initialize();

private:
    static inline MVector   nop(MVector v, MMatrix m);
    static inline MVector   vectorMatrixProduct(MVector v, MMatrix m);    
    static inline MVector   pointMatrixProduct(MVector v, MMatrix m);

public:
    static MTypeId          NODE_ID;
    static MString          NODE_NAME;

    static MObject          inputVectorAttr;
    static MObject          inputMatrixAttr;
    static MObject          operationAttr;

    static MObject          outputVectorAttr;
};