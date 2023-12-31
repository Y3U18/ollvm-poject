//===- Passes.h - Pass Entrypoints ------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This header file defines prototypes that expose pass constructors in the loop
// transformation library.
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_DIALECT_STANDARDOPS_TRANSFORMS_PASSES_H
#define MLIR_DIALECT_STANDARDOPS_TRANSFORMS_PASSES_H

#include "mlir/Pass/Pass.h"

namespace mlir {
namespace bufferization {
class BufferizeTypeConverter;
class GlobalCreator;
} // namespace bufferization

class RewritePatternSet;

void populateStdBufferizePatterns(
    bufferization::BufferizeTypeConverter &typeConverter,
    RewritePatternSet &patterns);

/// Creates an instance of std bufferization pass.
std::unique_ptr<Pass> createStdBufferizePass();

/// Creates an instance of func bufferization pass.
std::unique_ptr<Pass> createFuncBufferizePass();

/// Add patterns to bufferize tensor constants into global memrefs to the given
/// pattern list.
void populateTensorConstantBufferizePatterns(
    bufferization::GlobalCreator &globalCreator,
    bufferization::BufferizeTypeConverter &typeConverter,
    RewritePatternSet &patterns);

/// Creates an instance of tensor constant bufferization pass.
std::unique_ptr<Pass> createTensorConstantBufferizePass(unsigned alignment = 0);

//===----------------------------------------------------------------------===//
// Registration
//===----------------------------------------------------------------------===//

/// Generate the code for registering passes.
#define GEN_PASS_REGISTRATION
#include "mlir/Dialect/StandardOps/Transforms/Passes.h.inc"

} // namespace mlir

#endif // MLIR_DIALECT_STANDARDOPS_TRANSFORMS_PASSES_H
