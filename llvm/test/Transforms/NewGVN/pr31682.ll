; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt < %s -passes=newgvn -S | FileCheck %s
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"

%struct.foo = type { i32, i32, [2 x [4 x [6 x [6 x i16]]]] }

@global = external global %struct.foo*

define void @bar() {
; CHECK-LABEL: @bar(
; CHECK-NEXT:  bb:
; CHECK-NEXT:    [[TMP:%.*]] = load %struct.foo*, %struct.foo** @global
; CHECK-NEXT:    br label [[BB2:%.*]]
; CHECK:       bb2:
; CHECK-NEXT:    br i1 undef, label [[BB2]], label [[BB7:%.*]]
; CHECK:       bb7:
; CHECK-NEXT:    br label [[BB10:%.*]]
; CHECK:       bb10:
; CHECK-NEXT:    br label [[BB10]]
;
bb:
  %tmp = load %struct.foo*, %struct.foo** @global
  %tmp1 = getelementptr %struct.foo, %struct.foo* %tmp
  br label %bb2

bb2:                                              ; preds = %bb2, %bb
  %tmp3 = phi %struct.foo* [ undef, %bb ], [ %tmp6, %bb2 ]
  %tmp4 = getelementptr %struct.foo, %struct.foo* %tmp3, i64 0, i32 1
  %tmp5 = load i32, i32* %tmp4
  %tmp6 = load %struct.foo*, %struct.foo** @global
  br i1 undef, label %bb2, label %bb7

bb7:                                              ; preds = %bb2
  %tmp8 = phi %struct.foo* [ %tmp6, %bb2 ]
  %tmp9 = getelementptr %struct.foo, %struct.foo* %tmp8, i64 0, i32 1
  br label %bb10

bb10:                                             ; preds = %bb10, %bb7
  %tmp11 = load i32, i32* %tmp9
  br label %bb10
}
