; ModuleID = 'exp/layout_demo.cpp'
source_filename = "exp/layout_demo.cpp"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-darwin18.7.0"

%struct.Square = type { %struct.Shape.base, [4 x i8], %struct.Drawable.base, i16, [2 x i8] }
%struct.Shape.base = type <{ i32 (...)**, i32 }>
%struct.Drawable.base = type <{ i32 (...)**, %struct.Point }>
%struct.Point = type { i16, i16 }
%struct.Shape = type <{ i32 (...)**, i32, [4 x i8] }>
%struct.Drawable = type <{ i32 (...)**, %struct.Point, [4 x i8] }>

@_ZTV6Square = linkonce_odr unnamed_addr constant { [5 x i8*], [4 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i32, i32, i8*, i64, i8*, i64 }* @_ZTI6Square to i8*), i8* bitcast (double (%struct.Square*)* @_ZNK6Square4areaEv to i8*), i8* bitcast (double (%struct.Square*)* @_ZNK6Square9perimeterEv to i8*), i8* bitcast (i32 (%struct.Square*)* @_ZNK6Square4drawEv to i8*)], [4 x i8*] [i8* inttoptr (i64 -16 to i8*), i8* bitcast ({ i8*, i8*, i32, i32, i8*, i64, i8*, i64 }* @_ZTI6Square to i8*), i8* bitcast (i32 (%struct.Square*)* @_ZThn16_NK6Square4drawEv to i8*), i8* bitcast (i32 (%struct.Drawable*)* @_ZNK8Drawable8getStyleEv to i8*)] }, align 8
@_ZTVN10__cxxabiv121__vmi_class_type_infoE = external global i8*
@_ZTS6Square = linkonce_odr constant [8 x i8] c"6Square\00"
@_ZTVN10__cxxabiv117__class_type_infoE = external global i8*
@_ZTS5Shape = linkonce_odr constant [7 x i8] c"5Shape\00"
@_ZTI5Shape = linkonce_odr constant { i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv117__class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([7 x i8], [7 x i8]* @_ZTS5Shape, i32 0, i32 0) }
@_ZTS8Drawable = linkonce_odr constant [10 x i8] c"8Drawable\00"
@_ZTI8Drawable = linkonce_odr constant { i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv117__class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([10 x i8], [10 x i8]* @_ZTS8Drawable, i32 0, i32 0) }
@_ZTI6Square = linkonce_odr constant { i8*, i8*, i32, i32, i8*, i64, i8*, i64 } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv121__vmi_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([8 x i8], [8 x i8]* @_ZTS6Square, i32 0, i32 0), i32 0, i32 2, i8* bitcast ({ i8*, i8* }* @_ZTI5Shape to i8*), i64 2, i8* bitcast ({ i8*, i8* }* @_ZTI8Drawable to i8*), i64 4098 }
@_ZTV5Shape = linkonce_odr unnamed_addr constant { [4 x i8*] } { [4 x i8*] [i8* null, i8* bitcast ({ i8*, i8* }* @_ZTI5Shape to i8*), i8* bitcast (void ()* @__cxa_pure_virtual to i8*), i8* bitcast (void ()* @__cxa_pure_virtual to i8*)] }, align 8
@_ZTV8Drawable = linkonce_odr unnamed_addr constant { [4 x i8*] } { [4 x i8*] [i8* null, i8* bitcast ({ i8*, i8* }* @_ZTI8Drawable to i8*), i8* bitcast (void ()* @__cxa_pure_virtual to i8*), i8* bitcast (i32 (%struct.Drawable*)* @_ZNK8Drawable8getStyleEv to i8*)] }, align 8

; Function Attrs: noinline norecurse nounwind optnone
define i32 @main(i32 %argc, i8** %argv) #0 {
entry:
  %retval = alloca i32, align 4
  %argc.addr = alloca i32, align 4
  %argv.addr = alloca i8**, align 8
  %s1 = alloca %struct.Square, align 8
  %agg.tmp = alloca %struct.Point, align 2
  store i32 0, i32* %retval, align 4
  store i32 %argc, i32* %argc.addr, align 4
  store i8** %argv, i8*** %argv.addr, align 8
  %x = getelementptr inbounds %struct.Point, %struct.Point* %agg.tmp, i32 0, i32 0
  store i16 3, i16* %x, align 2
  %y = getelementptr inbounds %struct.Point, %struct.Point* %agg.tmp, i32 0, i32 1
  store i16 4, i16* %y, align 2
  %0 = bitcast %struct.Point* %agg.tmp to i32*
  %1 = load i32, i32* %0, align 2
  call void @_ZN6SquareC1Es5Point(%struct.Square* %s1, i16 signext 8, i32 %1)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN6SquareC1Es5Point(%struct.Square* %this, i16 signext %len, i32 %origin.coerce) unnamed_addr #1 align 2 {
entry:
  %origin = alloca %struct.Point, align 2
  %this.addr = alloca %struct.Square*, align 8
  %len.addr = alloca i16, align 2
  %0 = bitcast %struct.Point* %origin to i32*
  store i32 %origin.coerce, i32* %0, align 2
  store %struct.Square* %this, %struct.Square** %this.addr, align 8
  store i16 %len, i16* %len.addr, align 2
  %this1 = load %struct.Square*, %struct.Square** %this.addr, align 8
  %1 = load i16, i16* %len.addr, align 2
  %2 = bitcast %struct.Point* %origin to i32*
  %3 = load i32, i32* %2, align 2
  call void @_ZN6SquareC2Es5Point(%struct.Square* %this1, i16 signext %1, i32 %3)
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN6SquareC2Es5Point(%struct.Square* %this, i16 signext %len, i32 %origin.coerce) unnamed_addr #1 align 2 {
entry:
  %origin = alloca %struct.Point, align 2
  %this.addr = alloca %struct.Square*, align 8
  %len.addr = alloca i16, align 2
  %agg.tmp = alloca %struct.Point, align 2
  %0 = bitcast %struct.Point* %origin to i32*
  store i32 %origin.coerce, i32* %0, align 2
  store %struct.Square* %this, %struct.Square** %this.addr, align 8
  store i16 %len, i16* %len.addr, align 2
  %this1 = load %struct.Square*, %struct.Square** %this.addr, align 8
  %1 = bitcast %struct.Square* %this1 to %struct.Shape*
  call void @_ZN5ShapeC2E9ShapeKind(%struct.Shape* %1, i32 0)
  %2 = bitcast %struct.Square* %this1 to i8*
  %3 = getelementptr inbounds i8, i8* %2, i64 16
  %4 = bitcast i8* %3 to %struct.Drawable*
  %5 = bitcast %struct.Point* %agg.tmp to i8*
  %6 = bitcast %struct.Point* %origin to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 2 %5, i8* align 2 %6, i64 4, i1 false)
  %7 = bitcast %struct.Point* %agg.tmp to i32*
  %8 = load i32, i32* %7, align 2
  call void @_ZN8DrawableC2E5Point(%struct.Drawable* %4, i32 %8)
  %9 = bitcast %struct.Square* %this1 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*], [4 x i8*] }, { [5 x i8*], [4 x i8*] }* @_ZTV6Square, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %9, align 8
  %10 = bitcast %struct.Square* %this1 to i8*
  %add.ptr = getelementptr inbounds i8, i8* %10, i64 16
  %11 = bitcast i8* %add.ptr to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*], [4 x i8*] }, { [5 x i8*], [4 x i8*] }* @_ZTV6Square, i32 0, inrange i32 1, i32 2) to i32 (...)**), i32 (...)*** %11, align 8
  %len2 = getelementptr inbounds %struct.Square, %struct.Square* %this1, i32 0, i32 3
  %12 = load i16, i16* %len.addr, align 2
  store i16 %12, i16* %len2, align 4
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN5ShapeC2E9ShapeKind(%struct.Shape* %this, i32 %kind) unnamed_addr #1 align 2 {
entry:
  %this.addr = alloca %struct.Shape*, align 8
  %kind.addr = alloca i32, align 4
  store %struct.Shape* %this, %struct.Shape** %this.addr, align 8
  store i32 %kind, i32* %kind.addr, align 4
  %this1 = load %struct.Shape*, %struct.Shape** %this.addr, align 8
  %0 = bitcast %struct.Shape* %this1 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTV5Shape, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %0, align 8
  %kind2 = getelementptr inbounds %struct.Shape, %struct.Shape* %this1, i32 0, i32 1
  %1 = load i32, i32* %kind.addr, align 4
  store i32 %1, i32* %kind2, align 8
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #2

; Function Attrs: noinline nounwind optnone
define linkonce_odr void @_ZN8DrawableC2E5Point(%struct.Drawable* %this, i32 %origin.coerce) unnamed_addr #1 align 2 {
entry:
  %origin = alloca %struct.Point, align 2
  %this.addr = alloca %struct.Drawable*, align 8
  %0 = bitcast %struct.Point* %origin to i32*
  store i32 %origin.coerce, i32* %0, align 2
  store %struct.Drawable* %this, %struct.Drawable** %this.addr, align 8
  %this1 = load %struct.Drawable*, %struct.Drawable** %this.addr, align 8
  %1 = bitcast %struct.Drawable* %this1 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTV8Drawable, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %1, align 8
  %origin2 = getelementptr inbounds %struct.Drawable, %struct.Drawable* %this1, i32 0, i32 1
  %2 = bitcast %struct.Point* %origin2 to i8*
  %3 = bitcast %struct.Point* %origin to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %2, i8* align 2 %3, i64 4, i1 false)
  ret void
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr double @_ZNK6Square4areaEv(%struct.Square* %this) unnamed_addr #1 align 2 {
entry:
  %this.addr = alloca %struct.Square*, align 8
  store %struct.Square* %this, %struct.Square** %this.addr, align 8
  %this1 = load %struct.Square*, %struct.Square** %this.addr, align 8
  %len = getelementptr inbounds %struct.Square, %struct.Square* %this1, i32 0, i32 3
  %0 = load i16, i16* %len, align 4
  %conv = sext i16 %0 to i32
  %len2 = getelementptr inbounds %struct.Square, %struct.Square* %this1, i32 0, i32 3
  %1 = load i16, i16* %len2, align 4
  %conv3 = sext i16 %1 to i32
  %mul = mul nsw i32 %conv, %conv3
  %conv4 = sitofp i32 %mul to double
  ret double %conv4
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr double @_ZNK6Square9perimeterEv(%struct.Square* %this) unnamed_addr #1 align 2 {
entry:
  %this.addr = alloca %struct.Square*, align 8
  store %struct.Square* %this, %struct.Square** %this.addr, align 8
  %this1 = load %struct.Square*, %struct.Square** %this.addr, align 8
  %len = getelementptr inbounds %struct.Square, %struct.Square* %this1, i32 0, i32 3
  %0 = load i16, i16* %len, align 4
  %conv = sext i16 %0 to i32
  %mul = mul nsw i32 %conv, 4
  %conv2 = sitofp i32 %mul to double
  ret double %conv2
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr i32 @_ZNK6Square4drawEv(%struct.Square* %this) unnamed_addr #1 align 2 {
entry:
  %this.addr = alloca %struct.Square*, align 8
  store %struct.Square* %this, %struct.Square** %this.addr, align 8
  %this1 = load %struct.Square*, %struct.Square** %this.addr, align 8
  ret i32 2
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr i32 @_ZThn16_NK6Square4drawEv(%struct.Square* %this) unnamed_addr #1 align 2 {
entry:
  %this.addr = alloca %struct.Square*, align 8
  store %struct.Square* %this, %struct.Square** %this.addr, align 8
  %this1 = load %struct.Square*, %struct.Square** %this.addr, align 8
  %0 = bitcast %struct.Square* %this1 to i8*
  %1 = getelementptr inbounds i8, i8* %0, i64 -16
  %2 = bitcast i8* %1 to %struct.Square*
  %call = tail call i32 @_ZNK6Square4drawEv(%struct.Square* %2) #3
  ret i32 %call
}

; Function Attrs: noinline nounwind optnone
define linkonce_odr i32 @_ZNK8Drawable8getStyleEv(%struct.Drawable* %this) unnamed_addr #1 align 2 {
entry:
  %this.addr = alloca %struct.Drawable*, align 8
  store %struct.Drawable* %this, %struct.Drawable** %this.addr, align 8
  %this1 = load %struct.Drawable*, %struct.Drawable** %this.addr, align 8
  ret i32 1
}

declare void @__cxa_pure_virtual() unnamed_addr

attributes #0 = { noinline norecurse nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { argmemonly nounwind }
attributes #3 = { nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"Apple LLVM version 10.0.1 (clang-1001.0.46.4)"}
