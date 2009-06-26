// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 2009 Steve Nygard.  All rights reserved.

#import "CDObjectiveCProcessor.h"

@class CDOCClass, CDOCCategory;

@interface CDObjectiveC2Processor : CDObjectiveCProcessor
{
    NSMutableArray *classes;
    NSMutableArray *categories;
    NSMutableDictionary *classesByAddress;
}

- (id)initWithMachOFile:(CDMachOFile *)aMachOFile;
- (void)dealloc;

- (BOOL)hasObjectiveCData;

- (void)process;

- (void)loadSymbolTables;
- (void)loadDynamicSymbolTables;
- (void)loadClasses;
- (void)loadCategories;

- (CDOCCategory *)loadCategoryAtAddress:(uint64_t)address;

- (CDOCClass *)loadClassAtAddress:(uint64_t)address;
- (CDOCClass *)loadMetaClassAtAddress:(uint64_t)address;

- (NSArray *)loadMethodsAtAddress:(uint64_t)address;
- (NSArray *)loadIvarsAtAddress:(uint64_t)address;

@end