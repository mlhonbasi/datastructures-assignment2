/*
* @file         queueNode.cpp
* @description  Kuyruk için düğüm oluşturulması.
* @course       1.Öğretim 1-C 
* @assignment   2.Ödev
* @date         11 Aralık 2022
* @author       Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "QueueNode.hpp"

//Kuyruk düğümü sınıfının kurucusu.
queueNode::queueNode(int data)
{
    this->data = data;
    next = nullptr;
}

//Düğümün yok edicisi.
queueNode::~queueNode()
{
    
}